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
// 1) ������ Red or Black
// 2) ��Ʈ���� Black
// 3) Leaf(nil)���� Black
// 4) Red ����� �ڽ��� Black ( Double Red x)
// 5) �� ���� ���� �������� ���� ��ε��� ��� ���� ���� Black���

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
	Node* Search(Node* node, int key);  // ��� �Լ�����

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

