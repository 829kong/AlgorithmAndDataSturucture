#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Queue (FIFO : First-In-First-Out ���Լ���)

// front << [1][2][3][4] << rear(back)
// �Ϲ������� ���ú��� Ȱ�뼺�� ����.
// ��������� ���� ���� ���� ���� ������ �Ǵ°� �ո����̴�.

// queue�� deque�� �̿��ؼ� ����������.
template<typename T>
class Queue
{
	// ��ȯ ������ ����
	// [front][end][][][][][][][][][][][][][]
public:
	Queue()
	{
		_container.resize(100);
	}
	void push(const T& value)
	{
		// ���� �۾�
		if (_size == _container.size())
		{
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);
			
			// ������ ����
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