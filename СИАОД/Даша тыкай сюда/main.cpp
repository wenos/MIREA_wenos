#include <iostream>
#include "Hash_t.h"
#include <chrono>
using namespace std::chrono;
void bin_input(int);
void bin_output_string(int);
void bin_output();

int main() {
	Hash_t A(10);
	bool st = 1;
	int switch_on;
	std::cout << "Select an operation and enter its number \n";
	std::cout << "1. Create new binary file\n";
	std::cout << "2. Fill in the hash table\n";
	std::cout << "3. Find an element in the hash table by key\n";
	std::cout << "4. Delete an element of the hash table and binary file by key\n";
	std::cout << "5. Binary file output\n";
	std::cout << "6. Output of the hash table\n";
	while (st) {
		std::cout << "Command: ";
		std::cin >> switch_on;
		switch (switch_on)
		{
		case 1: {
			int n;
			std::cout << "Enter the number of entries in the file: ";
			std::cin >> n;
			bin_input(n);
			std::cout << "The binary file has been updated\n";
			break;
		}
		case 2: {
			A.input();
			std::cout << "Hash table created\n";
			break;
		}
		case 3: {
			int k;
			std::cout << "\ninput key\n";
			std::cin >> k;
			int num = A.find(k);
			if (num != -1) {
				std::cout << "Key found: ";
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				bin_output_string(num);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				auto duration = duration_cast<microseconds>(t2 - t1).count();
				std::cout << "time: " << duration << '\n';
			}
			else {
				std::cout << "Element not found\n";
			}
			break;
		}
		case 4: {
			int j;
			std::cout << "\nInput key\n";
			std::cin >> j;
			bool num_1 = A.delet(j);
			if (num_1) {
				std::cout << "Deletion completed\n";
			}
			else {
				std::cout << "Deletion failed, element not found\n";
			}
			break;
		}
		case 5: {
			std::cout << "\nBinary file\n";
			bin_output();
			break;
		}
		case 6: {
			std::cout << "\nHash table\n";
			A.output();
			break;
		}
		}
		std::cout << "Would you like to continue Yes - 1, No - 0: ";
		std::cin >> st;
	}

	return 0;
}


void bin_input(int n) {
	std::ofstream fout("first.bin", std::ios::binary);
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		note a;
		a.num = rand() * RAND_MAX + rand();
		if (i == 0 || i == n - 1 || i == n / 2) {
			a.num = i;
		}
		a.code = rand() % 10000 + 1;

		for (int j = 0; j < 6; ++j) {
			a.fam[j] = char(rand() % 26 + 65);
		}
		a.fam[6] = '\0';
		fout.write((char*)&a, sizeof(note));
	}
	fout.close();
}

void bin_output_string(int num) {
	std::ifstream fin("first.bin", std::ios::binary);
	note b;
	fin.seekg(num * sizeof(note), std::ios::beg);
	fin.read((char*)&b, sizeof(note));
	std::cout << b.num << " " << b.code << " " << b.fam << '\n';
	fin.close();
}

void bin_output() {
	std::ifstream f("first.bin", std::ios::binary);
	int i = 0;
	note a;
	while (f.read((char*)&a, sizeof(note))) {
		std::cout << i++ << " " << a.num << " " << a.code << " " << a.fam << '\n';
	}
	f.close();
}
