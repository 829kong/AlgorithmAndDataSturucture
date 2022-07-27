#pragma once

//			[10]
//		[5]		 [20]
//	 [3]	  [15]	 [30]

// 왼쪽노드는 항상 부모노드보다 작아야하고,
// 오른쪽노드는 항상 부모노드보다 커야한다.

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
};

class BinarySearchTree
{
public:
	void Print() { Print(_root, 10, 0); }
	void Print(Node* node, int x, int y);
	void Print_Inorder() { Print_Inorder(_root); };
	void Print_Inorder(Node* node);
	void insert(int key);
	int PrintKey(Node* node) { return node->key; }
	
	//TODO:
	Node* Search(Node* node, int key);  // 재귀 함수버전
	Node* Search2(Node* node, int key); // 루프 버전

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Delete(int key);
	void Delete(Node* node);
	void Replace(Node* u, Node* v);

private:
	Node* _root = nullptr;
};

