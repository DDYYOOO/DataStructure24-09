#pragma once
#include<iostream>

// 트리 : 나무처럼 생긴 자료구조
// 트리의 노드가 가질 수 있는 최대 수에 따른 분류
// 2개 : 이진트리(binary tree) <- 주로 사용하는 트리
// 3개 : (ternary tree)
// 4개 : (octree)

// 트리의 용어
// 노드 : 트리의 기본 요소로 데이터를 저장하는 단위
// 루트 : 최상위에 있는 노드 -> 부모가 없는 유일 노드
// 부모 노드 : 하위의 노드와 직접 연결된 노드
// 자식 노드 : 부모노드의 하위에 직접 연결된 노드
// 형제 노드 : 같은 부모를 가진 노드
// 조상 노드 : 특정 노드에서 루트까지 경로에 있는 모든 노드들
// 후손 노드 : 특정 노드의 모든 자식, 자식의 자식들을 포함한 노드들
// 레벨 : 루트로부터의 거리, 루트노들 레벨 : 0
// 높이 : 트리에서 가장 깊은 레벨을 의미
// 서브 트리 : 트리의 내부의 노드와 그 후손들로 구성된 트리
// 차수(degree) : 하나의 노드가 가진 자식 노드의 수
// 경로 : 하나의 노드에서 다른 노드로 이동할 때 거치는 노드들의 순서

// 트리
// 1. 루트가 한 개이여야 한다
// 2. 노드들이 순환하지 않아야한다. 

// 이진트리의 종류 
// 이진 트리 : 모든 노드들이 가질 수 있는 자식의 수(degree) 2개 이하로 구성된 자료구조
// 이진 탐색, 중간삽입 삭제가 빠른 자료구조 - 이진 검색 트리
// Full binary tree 
// Complete binary tree
// perfect binary tree

// 트리의 순회 방식
// PreOrder  전위 순회 (NLR)
// InOrder	 중위 순회 (LNR)
// PostOrder 후위 순회 (LRN)

// 균형 잡힌 이진 검색 트리
// Red - Black Tree, AVL Tree

// 1. 모든 노드는 빨간색 or 검은색이다
// 2. 루트 노드는 검은색이다
// 3. NIL(null leaf) 리프 노드들은 검은색이다, Null Left : 자료를 갖지 않고 트리의 끝을 나타내는 노드
// 4. 빨간색 노드의 자식은 검은색이다 (NO DOUBLE RED) <- 검은색의 자식이 검은색이여도 된다.
// 5. 모든 리프 노드에서 Black Depth는 같다.	모든 리프 노드에서 특정 노드로 가는 검은색 노드의 갯수가 같아야한다.

class Tree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}

	};

	void PreOrder(Node* root)	// 전위 순회
	{
		// 재귀 함수 : 자기 자신의 함수를 호출하는 함수
		if (root == nullptr)
			return;

		std::cout << root->data << " ";		// N
		PreOrder(root->left);				// L
		PreOrder(root->right);				// R

	}
	void InOrder(Node* root)	// 중위 순회
	{
		if (root == nullptr)
			return;

		InOrder(root->left);				// L
		std::cout << root->data << " ";		// N
		InOrder(root->right);				// R
	}
	void PostOrder(Node* root)	// 후위 순회
	{
		if (root == nullptr)
			return;

		PostOrder(root->left);				// L
		PostOrder(root->right);				// R
		std::cout << root->data << " ";		// N
	}
};

// BST : 이진 검색 트리
// 선형 자료구조에서 이진 검색이 비효율적이라서 이진 검색을 효율적으로 할 수 있는 자료구조

// 이진 검샘을 하기 위한 규칙
// 노드의 기준으로 왼쪽 노드는 자신보다 작은 값, 오른쪽 노드는 자신보다 큰 값을 저장
// 중복 허용 X

// 검색에 걸리는 시간 : logn
// 중간 삽입 삭제 : logn
// Insert
// Delelte

// 삭제 방법
// 1. 삭제하고자 하는 노드의 자식이 없을 때
// 2. 삭제하고자 하는 노드의 왼쪽에만 자식이 있을 때
// 3. 삭제하고자 하는 노드의 오른쪽에서만 자식이 있을 때
// 4. 양쪽에 자식이 있을 때

class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}

	};

private:
	Node* root;

	Node* Insert(Node* root, int value)
	{
		if (root == nullptr)
			return new Node(value);

		if (value < root->data)
		{
			root->left = Insert(root->left, value);
		}

		if (value > root->data)
		{
			root->right = Insert(root->right, value);
		}

		return root;
	}
	Node* Search(Node* root, int target)
	{
		if (root == nullptr || root->data == target)
			return root;

		if (target < root->data)
			return Search(root->left, target);
		else if(target > root->data)
			return Search(root->right, target);
	}
	void InOrder(Node* root)					
	{
		// LNR
		if (root == nullptr)
			return;

		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}

	// 노드의 삭제
	// 1. 리프 노드 또는 자식이 1개만 있을 경우 : 노드를 삭제하고 자식 노드를 부모 노드와 연결시켜준다.
	// 2. 자식이 2개이상 있을 경우 : case1. 

	Node* RemoveNode(Node* root, int target)
	{
		if (root == nullptr)
			return root;
		// 삭제할 노드를 찾는다
		if (root->data > target)
		{
			root->left = RemoveNode(root->left, target);
		}
		else if (root->data < target)
		{
			root->right = RemoveNode(root->right, target);
		}
		else      // 노드를 찾았다
		{
			// 노드를 찾았으면 그 노드의 자식이 1개 or 리프 노드일 때
			if (root->left == nullptr)
			{
				Node* tempNode = root->right;
				delete root;
				return tempNode;
			}
			else if (root->right == nullptr)
			{
				Node* tempNode = root->left;
				delete root;
				return tempNode;
			}
			
			// 자식이 2개이상일 경우
			// 왼쪽 노드를 부모를 올릴지, 오른쪽 노드를 부모로 올릴지 선택
			// 오른쪽을 선택할 시, 오른쪽 노드 중에서 가장 왼쪽 아래에 있는 노드를 부모로 변경
			Node* temp = MinValueNode(root->right);
			root->data = temp->data;
			root->right = RemoveNode(root->right, root->data);

		}
	}
	
	Node* MinValueNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(int value)
	{
		root = Insert(root, value);
	}

	bool search(int value)
	{
		return Search(root, value) != nullptr;
	}

	void inOrder()
	{
		// LNR
		if (root == nullptr)
			return;

		InOrder(root);
		std::cout << std::endl;
	}

	void remove(int target)
	{
		RemoveNode(root, target);
	}

	void LeftRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->right;
		oldTop->right = newTop->left;
		newTop->left = oldTop;

		if (isRoot)
			root = newTop;
	}

	void RightRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->left;
		oldTop->left = newTop->right;
		newTop->right = oldTop;

		if (isRoot)
			root = newTop;
	}

	Node* GetRoot() { return root; }
	
};

void TreeExample()
{
	// Tree 자료구조에 저장되어 있는 상태 
	// 데이터를 순회하는 방법 : PreOrder, InOrder, PostOrder
	Tree::Node* root = new Tree::Node(1);
	root->left = new Tree::Node(2);
	root->right = new Tree::Node(3);
	root->left->left = new Tree::Node(4);
	root->left->right = new Tree::Node(5);

	Tree myTree;

	// PreOrder의 결과 : 1 - 2 - 4 - 5 - 3
	std::cout << "====전위 순회(PreOrder)====" << std::endl;
	myTree.PreOrder(root);
	std::cout << std::endl;
	// InOrder의 결과 : 4 - 2 - 5 - 1 - 3
	std::cout << "====중위 순회(InOrder)====" << std::endl;
	myTree.InOrder(root);
	std::cout << std::endl;
	// PostOrder의 결과 : 4 - 5 - 2 - 3 - 1
	std::cout << "====후위 순회(PostOrder)====" << std::endl;
	myTree.PostOrder(root);
	std::cout << std::endl;

	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(40);
	bst.insert(17);
	bst.insert(49);

	bst.remove(7);
	//bst.remove(25);			// 오류 부분
	
	//bst.RightRotate(bst.GetRoot());
	
	bst.inOrder();

	std::cout << "탐색 결과 : " << (bst.search(30) ? "찾음" : "못찾음") << std::endl;
}