#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int menu(int fd) 
{
	int opt = 0, opt2 = 0;
	printf("Choose an option: \n");
	printf("1- Turn ON \n");
	printf("2- Turn OFF\n");
	printf("3- Exit\n");
	scanf("%d", &opt);
	
	if (opt == 1) {
		printf("Choose which Led to turn ON:\n");
		printf("1- Green Led\n");
		printf("2- Yellow Led\n");
		printf("3- Red Led\n");
		scanf("%d", &opt2);
	} 
	if (opt == 2) {
		printf("Choose which Led to turn OFF:\n");
		printf("1- Green Led\n");
		printf("2- Yellow Led\n");
		printf("3- Red Led\n");
		scanf("%d", &opt2);
		opt2 += 3;
	}
	if (opt == 3) {
		printf("Exiting...\n");
		return 3;
	}
	char data[2] = {opt2 + '0', '\n'};
	write(fd,data,2);

	return 0;
}
int main(){

	int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);

	if (fd < 0) {
		printf("STM32 NOT CONNECTED\n");
		return 1;
	}
	while(1){
	if(menu(fd) == 3)
		break;
	}
	close(fd);

	return 0;
}
