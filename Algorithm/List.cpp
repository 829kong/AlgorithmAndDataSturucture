#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Node // 양방향 연결 리스트
{
public:
	Node()
		:_prev(nullptr),_next(nullptr),_data(T())
	{}
	Node(const T& value)
		:_prev(nullptr),_next(nullptr),_data(value)
	{}
	~Node()
	{}
public:
	Node* _prev;
	Node* _next;
	T _data;
};

template<typename T>
class Iterator
{
public:
	Iterator()
		:_node(nullptr)
	{}
	Iterator(Node<T>* node)
		:_node(node)
	{}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return _node;
	}

	// it++
	Iterator operator++(int)
	{
		Node<T>* temp = _node;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return _node;
	}
	// it--
	Iterator operator--(int)
	{
		Node<T>* temp = _node;
		_node = _node->_prev;
		return temp;
	}
	// *it
	T& operator *()
	{
		return _node->_data;
	}
	
	// ==
	bool operator == (const Iterator & it)
	{
		return _node == it._node;
	}
	// !=
	bool operator != (const Iterator& it)
	{
		return _node != it._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List()
		:_size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
		
	}
	~List()
	{
		delete _head;
		delete _tail;
	}
	void push_back(const T& value)
	{
		AddNode(_tail, value); //tail뒤에 삽입
	}
	void pop_back()
	{
		RemoveNode(_tail->_prev); // tail의 전의 데이터 제거
	}

	// iterator 구현부
	using iterator = Iterator<T>;
	iterator begin(){ return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }
	iterator insert(const iterator& it, const T& value)
	{
		Node<T>* newNode = AddNode(it._node, value);
		return iterator(newNode);
	}
	iterator erase(const iterator& it)
	{
		Node<T>* newNode = RemoveNode(it._node);
		return iterator(newNode);
	}

private:
	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>();
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;
		newNode->_data = value;
		_size++;

		return newNode;
	}

	// [head] <-> [1] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> [nextNode] <-> [tail]
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;
		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;
		delete node;
		_size--;
		return nextNode;
	}

	
private:
	// [head] <-> [tail]
	Node<T>* _head;
	Node<T>* _tail;
	T _size;
};

int main()
{
	List<int> li;
	List<int>::iterator eraseIt;
	// [ ] <-> [ ] <-> [ ]
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else 
		{
			li.push_back(i);
		}
	}

	li.pop_back();
	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}

}