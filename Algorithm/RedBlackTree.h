#pragma once

enum class Color
{
	RED = 0,
	BLACK = 1,
};

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
	Color color = Color::BLACK;
};

// Red-Black Tree
// 1) 모든노드는 Red or Black
// 2) 루트노드는 Black
// 3) Leaf(nil)노드는 Black
// 4) Red 노드의 자식은 Black ( Double Red x)
// 5) 각 노드로 부터 리프까지 가는 경로들은 모두 같은 수의 Black노드

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();

	void Print();
	void Print(Node* node, int x, int y);
	void insert(int key);
	void insertFixup(Node* node);

	//TODO:
	Node* Search(Node* node, int key);  // 재귀 함수버전

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Delete(int key);
	void Delete(Node* node);
	void DeleteFixup(Node* node);
	void Replace(Node* u, Node* v);

	// Red-Black Tree
	void LeftRotate(Node* x);
	void RightRotate(Node* y);

private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};

