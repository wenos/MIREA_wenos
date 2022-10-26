#include <iostream>
#include <fstream>
#include <ctime>

struct node
{
	int key = NULL;
	int num = NULL;
	node* next = nullptr;
};

struct note {
	int num;
	unsigned int code;
	char fam[7];
};

int h(int, int);
void hash_add(node**, int, int, int, int&);
void hash_output(node**, int);
void hash_input(node**&, int&, int&);
int hash_find(node**, int, int);
bool hash_delete(node**, int, int, int&);
void bin_delete(int);
void bin_input(int n);
void bin_output_string(int num);
void bin_output();
node** rehash(node**, int&, int&);


int main() {
	int size = 10;
	int real_size = 0;
	node** h_table = new node * [size] {};
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
			hash_input(h_table, size, real_size);
			std::cout << "Hash table created\n";
			break;
		}
		case 3: {
			int k;
			std::cout << "\ninput key\n";
			std::cin >> k;
			int num = hash_find(h_table, size, k);
			if (num != -1) {
				std::cout << "Key found: ";
				bin_output_string(num);
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
			bool num_1 = hash_delete(h_table, size, j, real_size);
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
			hash_output(h_table, size);
			break;
		}
		}
		std::cout << "Would you like to continue Yes - 1, No - 0: ";
		std::cin >> st;
	}

	return 0;
}


int h(int key, int mod) {
	return key % mod;
}

void bin_delete(int num) {
	std::ifstream fin("first.bin", std::ios::binary);
	std::ofstream fout("second.bin", std::ios::binary);
	int i = 0;
	note a;
	while (fin.read((char*)&a, sizeof(note))) {
		if (i++ != num) {
			fout.write((char*)&a, sizeof(note));
		}
	}
	fin.close();
	fout.close();
	remove("first.bin");
	rename("second.bin", "first.bin");
}

bool hash_delete(node** h_table, int size, int key, int& real_size) {
	node* tmp = h_table[h(key, size)];
	if (tmp) {
		--real_size;
		if (tmp->key == key) {
			bin_delete(h_table[h(key, size)]->num);
			h_table[h(key, size)] = h_table[h(key, size)]->next;
		}
		else {
			node* prev = h_table[h(key, size)];
			while (tmp) {
				if (tmp->key == key) {
					bin_delete(h_table[h(key, size)]->num);
					prev->next = tmp->next;
				}
				prev = tmp;
				tmp = tmp->next;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

void hash_add(node** h_table, int size, int key, int num, int& real_size) {
	int res = h(key, size);
	node* tmp = new node;
	if (h_table[res]) {
		tmp->next = h_table[res];
	}
	tmp->key = key;
	tmp->num = num;
	h_table[res] = tmp;
	real_size++;
}

void hash_output(node** h_table, int size) {
	for (int i = 0; i < size; ++i) {
		node* tmp = h_table[i];
		while (tmp) {
			std::cout << i << " " << tmp->key << " " << tmp->num << '\n';
			tmp = tmp->next;
		}
	}
}

void hash_input(node**& h_table, int& size, int& real_size) {
	std::ifstream fin("first.bin", std::ios::binary);
	unsigned int i = 0;
	note b;
	while (fin.read((char*)&b, sizeof(note))) {
		hash_add(h_table, size, b.num, i++, real_size);
		if (float(real_size) / size > 0.75) {
			h_table = rehash(h_table, size, real_size);
		}
	}
}

int hash_find(node** h_table, int size, int key) {
	node* tmp = h_table[h(key, size)];
	while (tmp) {
		if (tmp->key == key) {
			return tmp->num;
		}
		tmp = tmp->next;
	}
	return -1;
}

node** rehash(node** h_table, int& size, int& real_size) {
	size *= 2;
	real_size = 0;
	node** new_hash_table = new node * [size] {};
	for (int i = 0; i < size / 2; ++i) {
		node* tmp = h_table[i];
		while (tmp) {

			hash_add(new_hash_table, size, tmp->key, tmp->num, real_size);
			tmp = tmp->next;
		}
		delete[] h_table[i];
	}
	delete[] h_table;
	return new_hash_table;
}

void bin_input(int n) {
	std::ofstream fout("first.bin", std::ios::binary);
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		note a;
		a.num = rand() * RAND_MAX + rand();
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