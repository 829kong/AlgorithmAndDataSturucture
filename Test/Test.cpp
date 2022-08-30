#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

int Combination(int n, int r)
{
	if (r == 0 || n == r)
		return 1;

	return Combination(n - 1, r - 1) + Combination(n - 1, r);
}


int main()
{
	__int64 start = GetTickCount64();
	int num = Combination(45, 6);
	__int64 end = GetTickCount64();

	cout << end - start << " ms" << endl;
}