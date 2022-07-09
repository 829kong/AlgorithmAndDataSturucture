#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

	//// 인접 행렬 버전
	//adjacent2 = vector<vector<int>>
	//{
	//	{0,1,0,1,0,0},
	//	{1,0,1,1,0,0},
	//	{0,0,0,0,0,0},
	//	{0,0,0,0,1,0},
	//	{0,0,0,0,0,0},
	//	{0,0,0,0,1,0},
	//};
}

vector<bool> discovered;
void Bfs(int here)
{
	// 누구에 의해 발견 되었는지?
	vector<int> parent(6, -1);
	// 시작점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		cout << "Visited : " << here << endl;

		for (int there : adjacent[here])
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			// 정보수집
			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

int main()
{
	CreateGraph();
	discovered = vector<bool>(6, false);
	Bfs(0);

}