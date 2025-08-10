#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main(){

	ofstream out("/dev/ttyACM0", ios::out);

	if (!out){
		cout<<"NO STM32 FOUND!" <<endl;
		return 1;
	}
	while(true){
	ifstream fd ("/sys/class/thermal/thermal_zone0/temp", ios::in);

	if (!fd){
		cout <<"ERROR OPENING THE FILE" << endl;
		return 1;
	}

	string line;

	getline(fd,line);

	out << line << "\n";
	out.flush();
	this_thread::sleep_for(chrono::seconds(1));
	
	}
	return 0;
}
