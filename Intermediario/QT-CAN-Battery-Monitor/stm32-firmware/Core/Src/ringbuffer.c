#include "ringbuffer.h"

void ringbuffer_init(RingBuffer  *buf)
{
	buf->head = buf->tail = 0;
}

bool isEmpty(RingBuffer *buf)
{	
	return (buf->head == buf->tail);
}

bool isFull(RingBuffer *buf)
{
	return ((buf->head + 1) % BUFFER_SIZE == buf->tail);
}

void ringbuffer_write(RingBuffer *buf, uint8_t data)
{
	if (isFull(buf)) 
		return;

	buf->buffer[buf->head] = data;
	buf->head = (buf->head + 1) % BUFFER_SIZE;
}

void ringbuffer_read(RingBuffer *buf, uint8_t *data)
{
	if (isEmpty(buf))
		return;

	*data = buf->buffer[buf->tail];
	buf->tail = (buf->tail + 1) % BUFFER_SIZE;

}	
int ringbuffer_count(RingBuffer *buf) {
    if (buf->head >= buf->tail)
        return buf->head - buf->tail;
    else
        return BUFFER_SIZE - buf->tail + buf->head;
}


bool ringbuffer_copy_line(RingBuffer *buf, char *data)
{
	if (isEmpty(buf))
		return false;

	int temp_tail = buf->tail;
	uint8_t i = 0;

	while (temp_tail != buf->head) {
		if (buf->buffer[temp_tail] == '\n')
			break;
		
		i++;
		temp_tail = (temp_tail + 1) % BUFFER_SIZE;
	}

	if (buf->buffer[temp_tail] != '\n'  || i >= BUFFER_SIZE - 1)
		return false;

	uint8_t count = 0;

	while (count <  i) {
		data[count++] = buf->buffer[buf->tail];
		buf->tail = (buf->tail + 1) % BUFFER_SIZE;
	}

	if (buf->buffer[buf->tail] == '\n')
		buf->tail = (buf->tail + 1) % BUFFER_SIZE;
	

	data[i] = '\0';

	return true;
}


