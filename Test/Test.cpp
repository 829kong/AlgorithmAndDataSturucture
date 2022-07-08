#include <iostream>
using namespace std;

template<typename T>
class Test
{
public:
	T& operator[] (const int pos)
	{
		return _data[pos];
	}
public:
	T* _data = nullptr;
};

int main()
{
	Test<int> T;

	int* _data = new  
}