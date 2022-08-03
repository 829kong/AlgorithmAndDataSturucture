#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// QuickSort
// 1단계 : 
// pivot >= arr[low]일 동안 low를 오른쪽으로 이동
// pivot <= arr[high]일 동안 high를 왼쪽으로 이동
// 2단계 :
// low < high라면, arr[low]와 arr[high] 데이터를 교체
// 3단계 :
// high <= low면 빠져나오고, pivot과 arr[high]교체
// 자리를 찾은 숫자를 제외하고, 나머지 부분을 재귀적으로 QuickSort
void QuickSort(vector<int>& v)
{
	int pivot = 0;
	int low = 1;
	int high = v.size() - 1;

	
}

int main()
{
	vector<int> v{ 5,1,3,7,9,2,4,6,8 };
	QuickSort(v);

}