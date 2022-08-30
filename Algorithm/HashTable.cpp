#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 해시 테이블 <- 면접에 자주 나오는 질문

//*****************************************************************
// Q) map vs hash_map (C++ 11 표준 unordered_map)
// map은 레드블랙트리 소위, 균형이진트리로 만들어져있어 트리구조로 관리를 함
// 데이터가 추가가 되거나 삭제가 되면 이진트리를 유지를 하지만
// 균형을 맞추어 한쪽으로 쏠리는것을 예방하는 형태로 되어있다
// 시간복잡도는 O(logN)을 따른다.
// 하지만, 속도적인 측면을 보았을때 hashmap이 훨씬더 빠르다.
// hashmap은 메모리를 내주고 속도를 취하는 방법이기 떄문에
// 속도적인 측면을 보았을때 충돌이 일어나지 않는다는 가정하에 더 빠르다.
//*****************************************************************


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

	// 테이블
	// 키를 알면, 데이터를 단번에 찾을 수 있다.
	
	// 문제의 상황
	// int32_max(3억)
	// 살을 내주는것도 정도껏!
	// 메모리도 무한은 아니다
}

// 보안
// id : rookiss + pw : qwer1234
// id : rookiss + pw : hash(qwer1234) -> fdsaerj1k#@$2jk123 (해쉬값)

// DB [rookiss][fdsaerj1k#@$2jk123]
// 비밀번호 찾기 -> 아이디 입력/폰 인증 -> 옛날에는 비밀번호를 알려줬었음 , 이제는 새 비밀번호를 입력해야됨

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
	int key = (userId % 1000); // hash 고유번호

	// 777번 유저 정보 세팅
	users[key] = User{ userId,"Rookiss" };

	// 777번 유저 이름은?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// 충돌문제
}

int main()
{
	TestTable();
	TestHash();

}