#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;

// 주제 : 정렬

// 1) 버블 정렬 (Bubble Sort)
// 시간 복잡도 : O(N^2)
// (N-1) + (N-2) + ... + 2 + 1
// 등차수열의 합 = N*(N-1)/2
// 매우 느리다. 데이터가 커지면 쓸수없는수준
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < (n - 1 -i) ; j++)
		{
			if (v[j] > v[j + 1])
			{
				::swap(v[j], v[j + 1]);
			}
		}
	}
}

// 2) 선택 정렬 (Selection Sort)
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();
	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i; // 가장 작은 값
		for (int j = i+1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}
		::swap(v[i], v[bestIdx]);
	}
}


// 3) 삽입 정렬 (Insertion Sort)
void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();
	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];
		int j;

		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j+1] = v[j];
			else
				break;
		}
		v[j + 1] = insertData;
	}
}


int main()
{
	vector<int> v = { 5,4,3,1,2 };
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//BubbleSort(v);
	//SelectionSort(v);
	InsertionSort(v);
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}



}