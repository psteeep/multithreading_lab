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



	ofstream result_file("result.txt", std::ios_base::app);


	if (original_file.is_open() && fake_file.is_open()) {
		while (getline(original_file, line) && getline(fake_file, line2))
		{
			sum_line++;

			if (line != line2) {
				result_file << sum_line << endl;
				cout << " - " << sum_line << " - ";
			}
			else
				continue;
			
		}
	}
	//result_file << this_thread::get_id() << endl;
	//cout << this_thread::get_id() << endl;
	original_file.close();
	fake_file.close();
	result_file.close();
};


int main() {
	
	
	thread th1(compare, "fake_file.txt");
	th1.join();
	cout << endl;
	thread th2(compare, "fake2_file.txt");
	th2.join();
	cout << endl;
	thread th3(compare, "fake3_file.txt");
	th3.join();
	cout << endl;
	thread th4(compare, "original2_file.txt");
	th4.join();

	/*
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	*/
	
	/*
	compare("fake_file.txt");
	cout << endl;
	compare("fake2_file.txt");
	cout << endl;
	compare("fake3_file.txt");
	cout << endl;
	compare("original2_file.txt");
	*/
	return 0;
}
