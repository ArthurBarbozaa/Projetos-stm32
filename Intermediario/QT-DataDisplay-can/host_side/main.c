#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/can.h>
#include <net/if.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int s;
struct sockaddr_can addr;
struct ifreq ifr;
struct can_frame frame;

void setupSocket()
{
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	strcpy(ifr.ifr_name, "vcan0" );
	ioctl(s, SIOCGIFINDEX, &ifr);

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	bind(s, (struct sockaddr *)&addr, sizeof(addr));
}

void sendCan(int id, int data1, int data2)
{
	if (id == 1) {
		frame.can_id = 0x100;
		frame.can_dlc = 2;
		frame.data[0] = data1;
		frame.data[1] = data2;
	}

	if (id == 2) {
		frame.can_id = 0x200;
		frame.can_dlc = 1;
		frame.data[0] = data1;
	}
	write(s, &frame, sizeof(frame));
}


int readBattery()
{
	int fd = open("/sys/class/power_supply/BAT1/capacity", O_RDONLY);

	if (fd < 0) {
		perror("Error reading battery level");
		return -1;
	}

	char buf[8];
	int n1 =  read(fd, buf, sizeof(buf) - 1);

	close(fd);
	
	 fd = open("/sys/class/power_supply/BAT1/status",O_RDONLY);

	if (fd < 0) {
		perror("Error reading battery status");
		return -1;
	}

	char buf2[12];
	int n2 = read(fd, buf2, sizeof(buf2) - 1);
	close(fd);
	int status = 0;
	if (strcmp(buf2, "Charging\n") == 0) {
		status = 1;
	}
	if (strcmp(buf2,"Full\n") == 0) {
		status = 2;
	}
	buf2[n2] = '\0';
	int data1 = atoi(buf);
	sendCan(1, data1, status);

}

int readTemperature()
{
	int fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);

	if (fd < 0) {
		perror("Error reading the cpu temperature");
		return -1;
	}

	char buf[8];

	int n = read(fd, buf, sizeof(buf) - 1);

	int data = atoi(buf) / 1000;

	close(fd);

	sendCan(2, data, 0);
}

 
int main() {

	setupSocket();

	while(1) {

		readBattery();
		readTemperature();
		sleep(2);	
	}
}
