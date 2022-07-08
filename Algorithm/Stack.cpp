#include <iostream>
#include<stack>
#include<vector>
using namespace std;

// Stack (LIFO Last-In-First-Out 후입선출)
// 되돌리기 ( Ctrl + Z )


template<typename T>
class Stack
{
public:
	Stack()
	{
	}
	~Stack()
	{
	}
	void push(const T& value)
	{
		_data.push_back(value);
	}
	void pop()
	{
		_data.pop_back();
	}
	T& top()
	{
		return _data.back();
	}
	bool empty()
	{
		return _data.empty();
	}
	int size() { return _data.size(); }

private:
	vector<T> _data;
};

int main()
{
	Stack<int> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);
	
	// 비었나?
	while (s.empty() == false)
	{
		// 최상위 원소
		int data = s.top();

		// 최상위 원소 삭제
		s.pop();
		cout << data << endl;
	}

	// 사이즈 체크
	int size = s.size();4
	
}