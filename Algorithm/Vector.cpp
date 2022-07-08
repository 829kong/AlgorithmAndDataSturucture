#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{}
	~Vector()
	{}

	int size() const { return _size; }

	int capacity(){ return _capacity; }

	void push_back(const T& value)
	{
		if (_size == _capacity) // ������� �뷮�� ������ Ȯ��
		{
			// ����
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}
		_data[_size] = value;
		_size++;

	}

	void clear()
	{
		_size = 0;
	}

	void reserve(int capacity)
	{
		if (_capacity == capacity)
			return;
		_capacity = capacity;

		// ���ο� �޸� �Ҵ�
		T * newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// ���� ������ ����
		if(_data)
			delete[] _data;

		// ������ ��ü
		_data = newData;
	}

	T& operator [](const int pos)
	{
		return _data[pos];
	}

private:
	int _size = 0;
	int _capacity = 0;
	T* _data= nullptr;
};


int main()
{
	Vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;


	return 0;
}