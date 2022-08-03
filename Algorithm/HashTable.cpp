#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 해시 테이블 <- 면접에 자주 나오는 질문

// Q) map vs hash_map (C++ 11 표준 unordered_map)

// map : Red_Blackk Tree
// - 추가 탐색/삭제 O(logN)

// C# dictionary = C++ map(X)
// C# dictionary = C++ unordered_map

// hash_map(unordered_map)
// - 추가/탐색/삭제 O(1)
// 메모리를 내주고 속도를 취한다

void TestTable()
{
	struct User
	{
		int userId = 0; //1~999
		string username;
	};
	vector<User> users;
	users.resize(1000);

	// 777번 유저 정보 세팅
	users[777] = User { 777,"Rookiss" };

	// 777번 유저 이름은?
	string name = users[777].username;
	cout << name << endl;
}

int main()
{
	TestTable();


}