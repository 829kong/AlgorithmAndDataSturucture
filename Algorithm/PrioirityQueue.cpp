#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T,typename Container = vector<T>,typename Predicate = less<T>>
class Priority_queue
{
public:
	void push(const T& value)
	{
		_node.push_back(value);
		
		int now = static_cast<int>(_node.size() - 1);
		while (now > 0)
		{
			int parent = static_cast<int>((now - 1) / 2);
			if (_pred(_node[now],_node[parent]))
				break;

			::swap(_node[now], _node[parent]);
			now = parent;
		}

	}
	void pop()
	{
		_node[0] = _node.back();
		_node.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;
			// 리프 끝에 도달했을 경우
			if (left >= _node.size())
				break;

			int next = now;

			// 왼쪽 노드
			if (_pred(_node[next], _node[left]))
				next = left;

			// 오른쪽 노드
			// 둘중 승자를 오른쪽과 비교
			if (right < _node.size() && _pred(_node[next], _node[right]))
				next = right;

			// 둘다 작다면 종료
			if (next == now)
				break;

			::swap(_node[next], _node[now]);
			now = next;


		}

		
	}
	T& top()
	{
		return _node[0];
	}
	bool empty()
	{
		return _node.empty();
	}

private:
	Container _node = {};
	Predicate _pred = {};
};


int main()
{
	Priority_queue<int,vector<int>> pq;

	pq.push(100);
	pq.push(300);
	pq.push(200);
	pq.push(500);
	pq.push(400);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}
}