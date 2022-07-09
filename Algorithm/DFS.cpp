#include <iostream>
#include <vector>
using namespace std;

// DFS (Depth First Search) : 깊이 우선 탐색
// BFS (Breadth First Search) : 너비 우선 탐색

struct Vertex {};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<vector<int>> adjacent2;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트 버전
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

	// 인접 행렬 버전
	adjacent2 = vector<vector<int>>
	{
		{0,1,0,1,0,0},
		{1,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
	};
}

// DFS

// Dfs(0)
// - Dfs(1)
// -- Dfs(2)
// -- Dfs(3)
// --- Dfs(4)
vector<bool> visited;
void Dfs(int here)
{
	// 방문
	visited[here] = true;
	cout << "Visited : " << here << endl;
	// 인접 리스트 version
	// 모든 인접 정점을 순회한다.
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			// 재귀함수
			Dfs(there);
	}

	// 인접 행렬 version
	// 모든 인접 정점을 순회한다.
	for (int there = 0; there < 6; there++)
	{
		if (adjacent2[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳이 있으면 방문한다.
		if (visited[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	visited = vector<bool>(6, false);
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}

int main()
{
	CreateGraph();
	
	DfsAll();


}