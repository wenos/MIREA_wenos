#include <iostream>
#include <fstream>
#define SHIFT 5
#define M 0x1F
#define N 1 + 10000000 / 32
int a[N]{};
int main1()
{
	int k = 15;
	std::ifstream f("test1.txt");
	for (int i = 0; i < k; ++i)
	{
		int n;
		f >> n;
		a[n >> SHIFT] |= (1 << (n & M));
	}
	f.close();
	std::ofstream g("output.txt");
	for (int j = 0; j < N; ++j) {
		unsigned int maska = 1;
		for (int i = 0; i < 32; ++i) {
			if (a[j] & maska) {
				g << (j << 5) + i << "\n";
			}
			maska = maska << 1;
		}
	}
	g.close();
	return 0;
}