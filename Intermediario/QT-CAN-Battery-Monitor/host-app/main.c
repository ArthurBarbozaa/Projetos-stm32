#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/can.h>

int readBattery() {
    int fd = open("/sys/class/power_supply/BAT1/capacity", O_RDONLY);
    if (fd < 0) {
        perror("Error reading battery");
        return -1;
    }
    
    char buf[8];
    int bytes_read = read(fd, buf, sizeof(buf) - 1);
    close(fd);
    
    if (bytes_read <= 0) return -1;
    buf[bytes_read] = '\0';
    return atoi(buf);
}

int main() {
    int fd = open("/dev/ttyACM0", O_WRONLY);
    if (fd < 0) {
        perror("STM32 not found");
        return 1;
    }
    
    while (1) {
        int battery = readBattery();
            struct can_frame frame;
            frame.can_id = 0x123;
            frame.can_dlc = 1;
            frame.data[0] = (uint8_t)battery;
            
	write(fd, &frame, sizeof(frame));
            
        sleep(20);  // Send every 30 seconds
    }
    
    close(fd);
    return 0;
}
