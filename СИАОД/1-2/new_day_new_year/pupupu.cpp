#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"


void create(std::string &full_name) {
	srand(time(0));
	std::ofstream tmp(full_name);
	for (int i = 0; i < rand() % 10 + 5; ++i) {
		if (i != 0) {
			tmp << '\n';
		}
		tmp << rand() % 100 + 1;
		for (int j = 0; j < rand() % 5; ++j) {
			tmp << " " << rand() % 100 + 1;
		}
	}
	tmp.close();
}

void print(std::string &full_name) {
	std::string a;
	std::string b;
	std::fstream g(full_name);
	while (!g.eof()) {
		std::getline(g, a);
		b += a + '\n';
	}
	g.close();
	std::cout << b;
}

void new_line(std::string &full_name, std::string &line) {
	std::ofstream file(full_name, std::ios::app);
	file << line;
	file.close();
}

int count_num(std::string &full_name) {
	std::ifstream f(full_name);
	int count = 0;
	while (!f.eof()) {
		std::string a = "";
		std::getline(f, a);
		for (int i = 0; i < a.size(); ++i) {
			if (int(a[i]) < 48 || int(a[i]) > 57) {
				++count;
			}
		}
		++count;
	}
	return count;
}


std::string search(std::string &full_name, int num) {
	std::ifstream f(full_name);
	int count = 1;
	while (!f.eof()) {
		std::string s = "";
		std::string a = "";
		std::getline(f, a);
		for (int i = 0; i < a.size(); ++i) {
			if (int(a[i]) >= 48 && int(a[i]) <= 57) {
				s += a[i];
			}
			if (int(a[i]) < 48 || int(a[i]) > 57 || i == a.size() - 1) {
				if (count++ == num) {
					return s;
				}
				else {
					s = "";
				}
			}
		}
	}
	return "";
}

void abc(std::string &full_name) {
	std::ofstream tmp("result.txt");
	std::ifstream f(full_name);
	while (!f.eof()) {
		std::string s = "";
		std::string a = "";
		std::getline(f, a);
		for (int i = 0; i < a.size(); ++i) {
			if (int(a[i]) >= 48 && int(a[i]) <= 57) {
				s += a[i];
			}
			if (int(a[i]) < 48 || int(a[i]) > 57 || i == a.size() - 1) {
				tmp << s << " " << s.size() << '\n';
				s = "";
			}
		}
	}
}


int main() {
	setlocale(0, "");
	std::cout << foo(12);
	return 0;
}