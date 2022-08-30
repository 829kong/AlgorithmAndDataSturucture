#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �ؽ� ���̺� <- ������ ���� ������ ����

//*****************************************************************
// Q) map vs hash_map (C++ 11 ǥ�� unordered_map)
// map�� �����Ʈ�� ����, ��������Ʈ���� ��������־� Ʈ�������� ������ ��
// �����Ͱ� �߰��� �ǰų� ������ �Ǹ� ����Ʈ���� ������ ������
// ������ ���߾� �������� �򸮴°��� �����ϴ� ���·� �Ǿ��ִ�
// �ð����⵵�� O(logN)�� ������.
// ������, �ӵ����� ������ �������� hashmap�� �ξ��� ������.
// hashmap�� �޸𸮸� ���ְ� �ӵ��� ���ϴ� ����̱� ������
// �ӵ����� ������ �������� �浹�� �Ͼ�� �ʴ´ٴ� �����Ͽ� �� ������.
//*****************************************************************


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

	// ���̺�
	// Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�.
	
	// ������ ��Ȳ
	// int32_max(3��)
	// ���� ���ִ°͵� ������!
	// �޸𸮵� ������ �ƴϴ�
}

// ����
// id : rookiss + pw : qwer1234
// id : rookiss + pw : hash(qwer1234) -> fdsaerj1k#@$2jk123 (�ؽ���)

// DB [rookiss][fdsaerj1k#@$2jk123]
// ��й�ȣ ã�� -> ���̵� �Է�/�� ���� -> �������� ��й�ȣ�� �˷������ , ������ �� ��й�ȣ�� �Է��ؾߵ�

void TestHash()
{
	struct User
	{
		int userId = 0; //1~int32_max
		string username;
	};
	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash ������ȣ

	// 777�� ���� ���� ����
	users[key] = User{ userId,"Rookiss" };

	// 777�� ���� �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// �浹����
}

int main()
{
	TestTable();
	TestHash();

}