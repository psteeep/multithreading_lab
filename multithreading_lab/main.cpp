#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>


using namespace std;

void compare(string fake_file_name) {
	string line;
	ifstream original_file("original_file.txt");

	string line2;
	ifstream fake_file(fake_file_name);

	int sum_line = 0;

	if (original_file.is_open() && fake_file.is_open()) {
		while (getline(original_file, line) && getline(fake_file, line2))
		{
			sum_line++;

			if (line != line2) {
				cout << sum_line;
			}
			else
				continue;
			cout << endl;
		}
	}
};


int main() {
	
	/*
	thread th1(compare, "fake_file.txt");
	thread th2(compare, "fake2_file.txt");
	thread th3(compare, "fake3_file.txt");
	thread th4(compare, "original2_file.txt");

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	*/

	compare("original2_file.txt");


	return 0;
}
