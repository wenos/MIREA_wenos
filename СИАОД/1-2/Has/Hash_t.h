#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <fstream>
#include <ctime>
struct node
{
	int key = NULL;
	int num = NULL;
	node* next = nullptr;
};
struct note
{
	int num;
	unsigned int code;
	char fam[7];
};
class Hash_t
{

private:
	node** h_table;
	int size;
	int real_size;
public:
	Hash_t(int);
	void add(int, int);
	void output();
	void input();
	int find(int);
	bool delet(int);
	void rehash();

};
#endif