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
		if (_size == _capacity) // 사이즈와 용량이 같으면 확장
		{
			// 증설
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

		// 새로운 메모리 할당
		T * newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 기존 데이터 삭제
		if(_data)
			delete[] _data;

		// 데이터 교체
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