#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �ؽ� ���̺� <- ������ ���� ������ ����

// Q) map vs hash_map (C++ 11 ǥ�� unordered_map)

// map : Red_Blackk Tree
// - �߰� Ž��/���� O(logN)

// C# dictionary = C++ map(X)
// C# dictionary = C++ unordered_map

// hash_map(unordered_map)
// - �߰�/Ž��/���� O(1)
// �޸𸮸� ���ְ� �ӵ��� ���Ѵ�

void TestTable()
{
	struct User
	{
		int userId = 0; //1~999
		string username;
	};
	vector<User> users;
	users.resize(1000);

	// 777�� ���� ���� ����
	users[777] = User { 777,"Rookiss" };

	// 777�� ���� �̸���?
	string name = users[777].username;
	cout << name << endl;
}

int main()
{
	TestTable();


}