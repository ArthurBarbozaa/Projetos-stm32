#ifndef RINGBUFFER_H
#define RINGBUFFER_H


#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 64

typedef struct {
	uint8_t buffer[BUFFER_SIZE];
	int head;
	int tail;
} RingBuffer;

extern RingBuffer buf;

void ringbuffer_init(RingBuffer  *buf);

bool isEmpty(RingBuffer *buf);

bool isFull(RingBuffer *buf);

void ringbuffer_write(RingBuffer *buf, uint8_t data);

void ringbuffer_read(RingBuffer *buf, uint8_t *data);

bool ringbuffer_copy_line(RingBuffer *buf, char *data);

#endif // !RINGBUFFER_H
