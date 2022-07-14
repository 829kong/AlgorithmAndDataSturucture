#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> v = { 1,2,3,4 };
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.pop_back();
	cout << v.back() << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
}