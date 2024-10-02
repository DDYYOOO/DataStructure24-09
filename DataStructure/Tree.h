#pragma once
#include<iostream>

// Ʈ�� : ����ó�� ���� �ڷᱸ��
// Ʈ���� ��尡 ���� �� �ִ� �ִ� ���� ���� �з�
// 2�� : ����Ʈ��(binary tree) <- �ַ� ����ϴ� Ʈ��
// 3�� : (ternary tree)
// 4�� : (octree)

// Ʈ���� ���
// ��� : Ʈ���� �⺻ ��ҷ� �����͸� �����ϴ� ����
// ��Ʈ : �ֻ����� �ִ� ��� -> �θ� ���� ���� ���
// �θ� ��� : ������ ���� ���� ����� ���
// �ڽ� ��� : �θ����� ������ ���� ����� ���
// ���� ��� : ���� �θ� ���� ���
// ���� ��� : Ư�� ��忡�� ��Ʈ���� ��ο� �ִ� ��� ����
// �ļ� ��� : Ư�� ����� ��� �ڽ�, �ڽ��� �ڽĵ��� ������ ����
// ���� : ��Ʈ�κ����� �Ÿ�, ��Ʈ��� ���� : 0
// ���� : Ʈ������ ���� ���� ������ �ǹ�
// ���� Ʈ�� : Ʈ���� ������ ���� �� �ļյ�� ������ Ʈ��
// ����(degree) : �ϳ��� ��尡 ���� �ڽ� ����� ��
// ��� : �ϳ��� ��忡�� �ٸ� ���� �̵��� �� ��ġ�� ������ ����

// Ʈ��
// 1. ��Ʈ�� �� ���̾��� �Ѵ�
// 2. ������ ��ȯ���� �ʾƾ��Ѵ�. 

// ����Ʈ���� ���� 
// ���� Ʈ�� : ��� ������ ���� �� �ִ� �ڽ��� ��(degree) 2�� ���Ϸ� ������ �ڷᱸ��
// ���� Ž��, �߰����� ������ ���� �ڷᱸ�� - ���� �˻� Ʈ��
// Full binary tree 
// Complete binary tree
// perfect binary tree

// Ʈ���� ��ȸ ���
// PreOrder  ���� ��ȸ (NLR)
// InOrder	 ���� ��ȸ (LNR)
// PostOrder ���� ��ȸ (LRN)

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

	void PreOrder(Node* root)	// ���� ��ȸ
	{
		// ��� �Լ� : �ڱ� �ڽ��� �Լ��� ȣ���ϴ� �Լ�
		if (root == nullptr)
			return;

		std::cout << root->data << " ";		// N
		PreOrder(root->left);				// L
		PreOrder(root->right);				// R

	}
	void InOrder(Node* root)	// ���� ��ȸ
	{
		if (root == nullptr)
			return;

		InOrder(root->left);				// L
		std::cout << root->data << " ";		// N
		InOrder(root->right);				// R
	}
	void PostOrder(Node* root)	// ���� ��ȸ
	{
		if (root == nullptr)
			return;

		PostOrder(root->left);				// L
		PostOrder(root->right);				// R
		std::cout << root->data << " ";		// N
	}
};

// BST : ���� �˻� Ʈ��
// ���� �ڷᱸ������ ���� �˻��� ��ȿ�����̶� ���� �˻��� ȿ�������� �� �� �ִ� �ڷᱸ��

// ���� �˻��� �ϱ� ���� ��Ģ
// ����� �������� ���� ���� �ڽź��� ���� ��, ������ ���� �ڽź��� ū ���� ����
// �ߺ� ��� X

// �˻��� �ɸ��� �ð� : logn
// �߰� ���� ���� : logn
// Insert
// Delelte

// ���� ���
// 1. �����ϰ��� �ϴ� ����� �ڽ��� ���� ��
// 2. �����ϰ��� �ϴ� ����� ���ʿ��� �ڽ��� ���� ��
// 3. �����ϰ��� �ϴ� ����� �����ʿ����� �ڽ��� ���� ��
// 4. ���ʿ� �ڽ��� ���� ��

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
	Node* Insert(Node* _root, int value)
	{
		if (_root == nullptr)
			return new Node(value);

		if (value < _root->data)
		{
			_root->left = Insert(_root->left, value);
		}

		if (value > _root->data)
		{
			_root->right = Insert(_root->right, value);
		}

		return _root;
	}
	Node* Search(Node* _root, int target)
	{
		if (_root == nullptr || _root->data == target)
			return _root;

		if (target < _root->data)
			return Search(_root->left, target);
		else if(target > _root->data)
			return Search(_root->right, target);
	}
	void InOrder(Node* _root)					// ���� �κ�
	{
		// LNR
		if (_root == nullptr)
			return;

		InOrder(_root->left);
		std::cout << root->data << " ";
		InOrder(_root->right);
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

		InOrder();
		std::cout << root->data << " ";
	}
};

void TreeExample()
{
	// Tree �ڷᱸ���� ����Ǿ� �ִ� ���� 
	// �����͸� ��ȸ�ϴ� ��� : PreOrder, InOrder, PostOrder
	Tree::Node* root = new Tree::Node(1);
	root->left = new Tree::Node(2);
	root->right = new Tree::Node(3);
	root->left->left = new Tree::Node(4);
	root->left->right = new Tree::Node(5);

	Tree myTree;

	// PreOrder�� ��� : 1 - 2 - 4 - 5 - 3
	std::cout << "====���� ��ȸ(PreOrder)====" << std::endl;
	myTree.PreOrder(root);
	std::cout << std::endl;
	// InOrder�� ��� : 4 - 2 - 5 - 1 - 3
	std::cout << "====���� ��ȸ(InOrder)====" << std::endl;
	myTree.InOrder(root);
	std::cout << std::endl;
	// PostOrder�� ��� : 4 - 5 - 2 - 3 - 1
	std::cout << "====���� ��ȸ(PostOrder)====" << std::endl;
	myTree.PostOrder(root);
	std::cout << std::endl;

	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);

	bst.InOrder();

	std::cout << "Ž�� ��� : " << (bst.search(30) ? "ã��" : "��ã��") << std::endl;
}