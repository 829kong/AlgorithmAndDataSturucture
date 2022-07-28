#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
//#include "BinarySearchTree.h"
#include "RedBlackTree.h"
using namespace std;
#include <thread>
// 주제 : 이진 탐색 트리

// 이진 탐색 (binary search)
// 상황) 배열에 데이터가 정렬되어 있다

// - 정렬된 배열을 이용해서 이진 탐색 가능 (numbers[mid])
// -- 그런데 배열의 단점은?
// --- 중간 삽입/삭제가 느리다!
// - 정렬된 연결 리스트로는 불가(임의 접근x)

vector<int> numbers;

void BinarySearch(int N)
{
	int begin = 0;
	int end = (int)numbers.size() - 1;
	
	while (begin <= end)
	{
		cout << "탐색 범위 : " << begin << " ~ " << end << endl;
		int mid = (begin+end)/ 2;

		if (N < numbers[mid])
		{
			cout << N << "<" << numbers[mid] << endl;
			end = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << ">" << numbers[mid] << endl;
			begin = mid + 1;
		}
		else
		{
			cout << "찾음!" << endl;
			break;
		}
	}

}


int main()
{
	RedBlackTree bst;

	bst.insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(10);
	bst.Print();
	this_thread::sleep_for(1s);



	return 0;
}