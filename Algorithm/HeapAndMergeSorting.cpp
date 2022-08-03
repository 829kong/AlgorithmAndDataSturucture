#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 힙 정렬 ( O(N logN) )
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int num : v)
		pq.push(num);

	v.clear();

	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}

// 병합 정렬
// 분할 정복 (Divide and Conquer)
// - 분할 (Divide)		문제를 더 단순하게 분할한다
// - 정복 (Conquer)		분할된 문제를 해결
// - 결합 (Combine)		결과를 취합하여 마무리

// [3][K][7][2][J][4][8][9]			8개 * 1
// [3][K][7][2] [J][4][8][9]		4개 * 2
// [3][K] [7][2] [J][4] [8][9]		2개 * 4
// [3] [K] [7] [2] [J] [4] [8] [9]	1개 * 8
// [3][K] [2][7] [4][J] [8][9]
// [2][3][7][K] [4][8][9][J]
// [2][3][4][7][8][9][J][K]

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	vector<int> temp;
	int leftIdx = left;
	int rightIdx = mid + 1;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	// 만약, 왼쪽이 먼저 끝났다면 오른쪽 데이터 전부 삽입
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v,int left ,int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

vector<int> Merge(vector<int> a, vector<int> b)
{
	vector<int> temp;
	int aIdx = 0;
	int bIdx = 0;
	int aEnd = a.size() - 1;
	int bEnd = b.size() - 1;

	while (aIdx <= aEnd && bIdx <= bEnd)
	{
		if (a[aIdx] <= b[bIdx])
		{
			temp.push_back(a[aIdx]);
			aIdx++;
		}
		else
		{
			temp.push_back(b[bIdx]);
			bIdx++;
		}
	}

	if (aIdx > aEnd)
	{
		while (bIdx <= bEnd)
		{
			temp.push_back(b[bIdx]);
			bIdx++;
		}
	}
	else
	{
		while (aIdx <= aEnd)
		{
			temp.push_back(a[aIdx]);
			aIdx++;
		}
	}


	return temp;
}

int main()
{
	/*vector<int> v;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 50;
		v.push_back(randValue);
	}
	MergeSort(v, 0, v.size() - 1);*/

	vector<int> a{ 5,6,7,8,9 };
	vector<int> b{ 1,2,3,4,5 };
	vector<int> c = Merge(a, b);


}