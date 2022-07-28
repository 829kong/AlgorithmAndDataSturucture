#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
//#include "BinarySearchTree.h"
#include "RedBlackTree.h"
using namespace std;
#include <thread>
// ���� : ���� Ž�� Ʈ��

// ���� Ž�� (binary search)
// ��Ȳ) �迭�� �����Ͱ� ���ĵǾ� �ִ�

// - ���ĵ� �迭�� �̿��ؼ� ���� Ž�� ���� (numbers[mid])
// -- �׷��� �迭�� ������?
// --- �߰� ����/������ ������!
// - ���ĵ� ���� ����Ʈ�δ� �Ұ�(���� ����x)

vector<int> numbers;

void BinarySearch(int N)
{
	int begin = 0;
	int end = (int)numbers.size() - 1;
	
	while (begin <= end)
	{
		cout << "Ž�� ���� : " << begin << " ~ " << end << endl;
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
			cout << "ã��!" << endl;
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