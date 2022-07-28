#include "RedBlackTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

void ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}


RedBlackTree::RedBlackTree()
{
	_nil = new Node();
	_root = _nil;
}

RedBlackTree::~RedBlackTree()
{
	delete _nil;
}

void RedBlackTree::Print()
{
	::system("cls");
	ShowConsoleCursor(false);
	Print(_root, 10, 0);
}

void RedBlackTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x, y);

	if (node->color == Color::BLACK)
		SetCursorColor(ConsoleColor::BLUE);
	else
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}


void RedBlackTree::insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	// 어느 노드 위치에 삽입을 할건지 순회
	Node* node = _root;
	Node* parent = _nil;

	while (node != _nil)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	newNode->parent = parent;


	if (parent == _nil)
		_root = newNode;
	else if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	newNode->left = _nil;
	newNode->right = _nil;
	newNode->color = Color::RED;
	insertFixup(newNode);
}

void RedBlackTree::insertFixup(Node* node)
{
	// 1) p = red, uncle = red
	// -> p = black, uncle = black, pp = red로 바꿈
	// 2) p = red, uncle = black (triangle)
	// -> 회전을 통해 case3으로 바꿈
	// 3) p = red, uncle = black (list)
	// -> 색상 변경 + 회전

	while (node->parent->color == Color::RED)
	{
		//     [pp(B)]
		//  [p(R)]    [u(?)]
		//    [n(R)] 
		if (node->parent == node->parent->parent->left)
		{
			Node* uncle = node->parent->parent->right;
			if (uncle->color == Color::RED)
			{
				uncle->color = Color::BLACK;
				node->parent->color = Color::BLACK;
				node->parent->parent->color = Color::RED;
				node = node->parent->parent;
			}
			else // uncle == BLACK
			{
				//     [pp(B)]
                //  [p(R)]    [u(B)]      <<- triangle
                //    [n(R)] 	
				if (node == node->parent->right) //triangle 타입
				{
					node = node->parent;
					LeftRotate(node);
				}

				//     [pp(B)]
                //  [p(R)]    [u(B)]      <<- list
                //[n(R)] 
				node->parent->color = Color::BLACK;
				node->parent->parent->color = Color::RED;
				RightRotate(node->parent->parent);
			}
		}
		//     [pp(B)]
		//  [u(?)]    [p(R)]
		//    [n(R)] 
		else
		{
			Node* uncle = node->parent->parent->left;
			if (uncle->color == Color::RED)
			{
				uncle->color = Color::BLACK;
				node->parent->color = Color::BLACK;
				node->parent->parent->color = Color::RED;
				node = node->parent->parent;
			}
			else // uncle == BLACK
			{

				if (node == node->parent->left) //triangle 타입
				{
					node = node->parent;
					RightRotate(node);
				}

				node->parent->color = Color::BLACK;
				node->parent->parent->color = Color::RED;
				LeftRotate(node->parent->parent);
			}
		}
		

	}
	_root->color = Color::BLACK;
}

Node* RedBlackTree::Search(Node* node, int key)
{
	if (node == _nil || node->key == key)
	{
		return node;
	}

	if (key < node->key)
		return Search(node->left, key);
	else if (key > node->key)
		return Search(node->right, key);
}


Node* RedBlackTree::Min(Node* node)
{
	while (node->left != _nil)
	{
		node = node->left;
	}

	return node;
}

Node* RedBlackTree::Max(Node* node)
{
	while (node->right != _nil)
	{
		node = node->right;
	}

	return node;
}

Node* RedBlackTree::Next(Node* node)
{
	if (node->right != _nil)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent != _nil && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void RedBlackTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

// case 1. 삭제할 노드의 자식노드가 없을때
// case 2. 삭제할 노드의 자식노드가 1개일때
// case 3. 삭제할 노드의 자식노드가 2개일때
void RedBlackTree::Delete(Node* node)
{
	if (node == _nil)
		return; 

	if (node->left == _nil)
	{
		Color color = node->color;
		Node* right = node->right;
		Replace(node, node->right);

		if (color == Color::BLACK)
			DeleteFixup(right);
	}
	else if (node->right == _nil)
	{
		Color color = node->color;
		Node* left = node->left;
		Replace(node, node->left);

		if (color == Color::BLACK)
			DeleteFixup(left);
	}
	else
	{
		Node* nextNode = Next(node);
		node->key = nextNode->key;
		Delete(nextNode);
	}
}

// 먼저 BST 삭제 실행
// - Case1) 삭제할 노드가 Red -> 그냥 삭제! 끝!
// - Case2) root가 DB-> 그냥 추가 Black 삭제! 끝!
// - Case3) DB의 sibling 노드가 Red
// -- s = black, p = red (s <-> p 색상 교환)
// -- DB 방향으로 rotate(p)
// -- goto other case
// - Case4) DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
// -- 추가 Black을 parent에게 이전
// --- p가 Red이면 Black됨.
// --- p가 black이면 DB됨.
// -- s = red
// -- p를 대상으로 알고리즘 이어서 실행 (DB가 여전히 존재하면)
// - Case5) DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
// -- s <-> near 색상 교환
// -- far 방향으로 rotate(s)
// -- goto case 6
// - Case6) DB의 sibling 노드가 Black && sibling의 far child = red
// - p <-> s 색상 교환
// - far = black
// - rotate(p) (DB방향으로)
// - 추가 Black제거
void RedBlackTree::DeleteFixup(Node* node)
{
	Node* x = node;

	// [Case1][Case2]
	while (x != _root && x->color == Color::BLACK)
	{
		//      [p(B)]
		// [x(DB)]  [s(R)]
		//         [1]

		//          [s(B)]
		//      [p(R)]
		// [x(DB)]  [1]
		if (x == x->parent->left)
		{
			// [Case3]
			Node* s = x->parent->right;
			if (s->color == Color::RED)
			{
				s->color = Color::BLACK;
				s->parent->color = Color::RED;
				LeftRotate(s->parent);
				s = x->parent->right; // [1]
			}
			// [Case4]
			if (s->left->color == Color::BLACK && s->right->color == Color::BLACK)
			{
				s->color = Color::RED;
				x = x->parent;
			}
			else
			{
				// [Case5]

				//        [p(B)]
				// [x(DB)]      [s(B)]
				//         [near(R)][far(B)]

				//        [p(B)]
				// [x(DB)]     [near(B)]
				//					[s(R)]
				//						 [far(B)]
				if (s->right->color == Color::BLACK)
				{
					s->left->color == Color::BLACK;
					s->color == Color::RED;
					RightRotate(s);
					s = x->parent->right;
				}

				// [Case6]
				// - p <-> s 색상 교환
				// - far = black
				// - rotate(p) (DB방향으로)
				// - 추가 Black제거
				// 
				//        [p(B)]
				// [x(DB)]     [s(B)]
				//					[far(R)]
				s->color = x->parent->color;
				x->parent->color = Color::BLACK;
				s->right->color = Color::BLACK;
				LeftRotate(x->parent);
				x = _root;
			}
		}
		else
		{
			// [Case3]
			Node* s = x->parent->left;
			if (s->color == Color::RED)
			{
				s->color = Color::BLACK;
				s->parent->color = Color::RED;
				LeftRotate(s->parent);
				s = x->parent->left; // [1]
			}
			// [Case4]
			if (s->right->color == Color::BLACK && s->left->color == Color::BLACK)
			{
				s->color = Color::RED;
				x = x->parent;
			}
			else
			{
				// [Case5]
				if (s->left->color == Color::BLACK)
				{
					s->right->color == Color::BLACK;
					s->color == Color::RED;
					LeftRotate(s);
					s = x->parent->left;
				}

				// [Case6]
				s->color = x->parent->color;
				x->parent->color = Color::BLACK;
				s->left->color = Color::BLACK;
				RightRotate(x->parent);
				x = _root;
			}
		}

		x->color = Color::BLACK;
	}
}

// u 서브트리를 v 서브트리로 교체
void RedBlackTree::Replace(Node* u, Node* v)
{
	if (u->parent == _nil)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

		v->parent = u->parent;

	delete u;
}

//     [y]
//  [x]   [3]
// [1][2]
//               right Rotate(위에서 아래)
//     [x]
//  [1]   [y]
//       [2][3]

void RedBlackTree::LeftRotate(Node* x)
{
	Node* y = x->right;
	y->parent = x->parent;
	if (x->parent == _nil)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	x->parent = y;
	x->right = y->left;
	if (y->left != _nil)
		y->left->parent = x;
	y->left = x;
}

void RedBlackTree::RightRotate(Node* y)
{
	Node* x = y->left;
	x->parent = y->parent;
	if (y->parent == _nil)
		_root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	y->parent = x;
	y->left = x->right;
	if (x->right != _nil)
		x->right->parent = y;
	x->right = y;
}
