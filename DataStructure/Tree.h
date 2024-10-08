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
// 1. ��Ʈ�� �� ���̿��� �Ѵ�
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

// ���� ���� ���� �˻� Ʈ��
// Red - Black Tree, AVL Tree

// 1. ��� ���� ������ or �������̴�
// 2. ��Ʈ ���� �������̴�
// 3. NIL(null leaf) ���� ������ �������̴�, Null Left : �ڷḦ ���� �ʰ� Ʈ���� ���� ��Ÿ���� ���
// 4. ������ ����� �ڽ��� �������̴� (NO DOUBLE RED) <- �������� �ڽ��� �������̿��� �ȴ�.
// 5. ��� ���� ��忡�� Black Depth�� ����.	��� ���� ��忡�� Ư�� ���� ���� ������ ����� ������ ���ƾ��Ѵ�.

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

	// ����� ����
	// 1. ���� ��� �Ǵ� �ڽ��� 1���� ���� ��� : ��带 �����ϰ� �ڽ� ��带 �θ� ���� ��������ش�.
	// 2. �ڽ��� 2���̻� ���� ��� : case1. 

	Node* RemoveNode(Node* root, int target)
	{
		if (root == nullptr)
			return root;
		// ������ ��带 ã�´�
		if (root->data > target)
		{
			root->left = RemoveNode(root->left, target);
		}
		else if (root->data < target)
		{
			root->right = RemoveNode(root->right, target);
		}
		else      // ��带 ã�Ҵ�
		{
			// ��带 ã������ �� ����� �ڽ��� 1�� or ���� ����� ��
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
			
			// �ڽ��� 2���̻��� ���
			// ���� ��带 �θ� �ø���, ������ ��带 �θ�� �ø��� ����
			// �������� ������ ��, ������ ��� �߿��� ���� ���� �Ʒ��� �ִ� ��带 �θ�� ����
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
	bst.insert(40);
	bst.insert(17);
	bst.insert(49);

	bst.remove(7);
	//bst.remove(25);			// ���� �κ�
	
	//bst.RightRotate(bst.GetRoot());
	
	bst.inOrder();

	std::cout << "Ž�� ��� : " << (bst.search(30) ? "ã��" : "��ã��") << std::endl;
}