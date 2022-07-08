#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Queue (FIFO : First-In-First-Out 선입선출)

// front << [1][2][3][4] << rear(back)
// 일반적으로 스택보다 활용성이 높다.
// 통상적으로 먼저 들어온 것이 먼저 진행이 되는게 합리적이다.

// queue는 deque를 이용해서 구현되있음.
template<typename T>
class Queue
{
	// 순환 구조로 구현
	// [front][end][][][][][][][][][][][][][]
public:
	Queue()
	{
		_container.resize(100);
	}
	void push(const T& value)
	{
		// 증설 작업
		if (_size == _container.size())
		{
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);
			
			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}
			_container.swap(newData);
			_front = 0;	
			_end = _size;
		}
		_container[_end] = value;
		_end = (_end + 1) % _container.size();
		_size++;
	}
	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}
	T& front()
	{
		return _container[_front];
	}
	bool empty() { return _size == 0; }
	int size() { return _size; }
private:
	int _front = 0;
	int _end = 0;
	int _size = 0;
	vector<T> _container;
};

int main()
{
	Queue<int> q;

	for (int i = 0; i < 100; ++i)
		q.push(i);

	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();

}