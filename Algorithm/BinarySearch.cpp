#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "BinarySearchTree.h"
using namespace std;

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
	BinarySearchTree bst;

	bst.insert(20);
	bst.insert(10);
	bst.insert(30);
	bst.insert(25);
	bst.insert(50);
	bst.insert(26);
	bst.insert(40);

	bst.Delete(20);

	bst.Print();
	cout << endl;


	return 0;
}