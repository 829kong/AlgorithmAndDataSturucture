#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// QuickSort
// 1�ܰ� : 
// pivot >= arr[low]�� ���� low�� ���������� �̵�
// pivot <= arr[high]�� ���� high�� �������� �̵�
// 2�ܰ� :
// low < high���, arr[low]�� arr[high] �����͸� ��ü
// 3�ܰ� :
// high <= low�� ����������, pivot�� arr[high]��ü
// �ڸ��� ã�� ���ڸ� �����ϰ�, ������ �κ��� ��������� QuickSort
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