#include <iostream>
#include<stack>
#include<vector>
using namespace std;

// Stack (LIFO Last-In-First-Out ���Լ���)
// �ǵ����� ( Ctrl + Z )


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

	// ����
	s.push(1);
	s.push(2);
	s.push(3);
	
	// �����?
	while (s.empty() == false)
	{
		// �ֻ��� ����
		int data = s.top();

		// �ֻ��� ���� ����
		s.pop();
		cout << data << endl;
	}

	// ������ üũ
	int size = s.size();4
	
}