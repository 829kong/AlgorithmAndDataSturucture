#include <iostream>
#include <vector>
#include <list>
using namespace std;

void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			return;
		}
	}
}

void CreateGraph_2()
{
	struct Vertex
	{
		
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			return;
		}
	}

}

void CreateGraph_3()
{
	struct Vertex {};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// 6x6 행렬
	// [x][o][x][o][x][x]
	// [o][x][o][o][x][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][o][x]
	// [x][x][x][x][x][x]
	// [x][x][x][x][o][x]

	// 읽는 방법 : adjacent[from][to]
	// 행렬을 이용한 그래프 표현(2차원 배열)
	// 메모리 소모가 심하지만 빠른 접근이 가능하다
	// 간선이 많은 경우 이점이 있다.
	vector<vector<bool>> adjacent(6, vector<bool>(6, false)); // 이중벡터 : 6개의 벡터를 가지고있고 6개의 false값을 가진 벡터로 초기화 
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = adjacent[0][3];

	// 가중치 그래프
	vector<vector<int>> adjacent2 =
	{
		vector<int>{-1,15,-1,35,-1,-1},
		vector<int>{15,-1,+5,10,-1,-1},
		vector<int>{-1,-1,-1,-1,-1,-1},
		vector<int>{-1,-1,-1,-1,+5,-1},
		vector<int>{-1,-1,-1,-1,-1,-1},
		vector<int>{-1,-1,-1,-1,+5,-1}
	};



}

int main()
{
	CreateGraph_1();
	CreateGraph_2();
	CreateGraph_3();


	return 0;
}