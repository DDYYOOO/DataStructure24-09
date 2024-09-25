#pragma once
#include<iostream>
#include<queue>

/*
  �ڷᱸ�� : �����̳ʸ� �����ؼ� ������ ���صΰ� ����ϴ� ��� �ڷᱸ��
  �ڷᱸ���� �����͸� ������ �� ���� �� �ڷᰡ ���� ������ ������ �ڷᱸ��
  ex) ���ǥ�� ���´� -> ������� ���� ���� -> ���� �� ����� ���� ���ǥ�� ���´� -> ���� �������� �� ����� ���� �������� ó���Ѵ�

  ť �ڷᱸ�� ����
  - �����Ͱ� ��µǴ� �ε����� front�̸����� ǥ��
  - �����Ͱ� ����Ǵ� �ε����� rear�̸����� ǥ��
  - ���� ť front rear �ʱⰪ���� �ǵ��� �� �� ����.


*/

// �����ؾ��� �Լ�
// �Է� �� ���� : push, pop 
// �ʵ� �� ǥ�� : empty(), size(), front(), back()

template<typename T>
class ArrayBasedQueue
{
private:
	T* queue;		// �����͸� �����ϱ� ���� �迭 �̸�
	int front;		// ��� ��ġ�� ����Ű�� �ε���
	int rear;		// �Է� ��ġ�� ����Ű�� �ε���
	int iCount;		// ���� �ڷᱸ���� ������ ����
public:
	// ������, �Ҹ���
	ArrayBasedQueue(int size = 10)
	{
		queue	= new T[size];
		front	= 0;
		rear	= 0;
		iCount	= 0;
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}

	// Accesor : �ʵ忡 ������ ���� �Լ�
	int Size()
	{
		return iCount;
	}
	int Front()
	{
		return queue[front];
	}
	int Rear()
	{
		return queue[rear - 1];
	}

	bool Empty()
	{
		return iCount <= 0 ? true : false;
	}

	// Main Method : ����, ����
	void Push(T data)
	{
		queue[rear] = data;		// queue �迭 data ����
		rear++;					// rear ����, ����
		iCount++;				// ���� ����
	}
	void Pop()
	{
		if (iCount != 0)// queue ������� �ʾ��� ��
		{
			front++;			// queue �迭 front ����
			iCount--;			// ���� ����	
		}
		else
		{
			std::cout << "ť�� ������ϴ�" << std::endl;
		}
	}

	void Print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}
};

// �ٸ� Ŭ���������� Node�� �� �� ���� ����ü ����(���뼺)
//template<typename T>
//struct Node
//{
//	T data;
//	Node* pNext;
//};

template<typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T data;
		QueueNode* pNext;
		
		QueueNode(T _data, QueueNode* pnode)
		{
			data = _data;
			pNext = pnode;
		}
	};

	QueueNode* front;
	QueueNode* rear;
	int iCount;
public:
	// ������, �Ҹ���
	LinkedQueue()
	{
		front	= nullptr;
		rear	= nullptr;
		iCount	= 0;
	}
	~LinkedQueue() {}

	// Accessor
	T Front() { return front->data; }
	T Back() { return rear->data; }
	int Size() { return iCount; }
	
	bool Empty() { return iCount <= 0 ? true : false; }

	// Main Method(�Է�, ����)
	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);		// newNode �����Ҵ�
		//QueueNode* newNode = new QueueNode;		// �� �ڵ�� ���� �ڵ�
		//newNode->data = data;
		//newNode->pNext = nullptr;
		
		if (Empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->pNext = newNode;	// ������ �������� ���� �����Ϳ� ���� �Ҵ��� ��带 �־��ش�
			rear = newNode;			// ���ο� ��带 rear�� ���������ش�.
		}
		
		iCount++;
	}
	void Pop()
	{
		if (Empty())
		{
			std::cout << "ť�� ������ϴ�" << std::endl;
			return;
		}
		
		QueueNode* oldNode = front;		// ������ ��带 ����
		front = front->pNext;			// ������ front����� ���� ��带 front�� ����
		delete oldNode;
		iCount--;

	}
};

template<typename T>
class CircularQueue
{
	// �迭 ��� ���� ť
private:
	T* cQueue;
	int front;
	int rear;
	int iCount;
	int iMaxCount;
public:
	CircularQueue(int size = 10)
	{
		cQueue = new T[size];
		front = 0;
		rear = 0;
		iCount = 0;
		iMaxCount = size;
	}
	~CircularQueue()
	{
		delete[] cQueue;
	}

	// Accessor
	T Front() { return cQueue[front]; }
	T Rear() { return cQueue[rear - 1]; }
	T CurrentSize() { return iCount; }
	T Size() { return iMaxCount; }
	bool Empty() { return iCount <= 0 ? true : false; }

	// Main method
	void Push(int data)
	{
		cQueue[rear] = data;
		rear++;
		iCount++;
		//front = rear;
	}
	void Pop()
	{
		if (iCount != 0)
		{
			front++;
			iCount--;
			//rear = front;
		}
		else
		{
			std::cout << "ť�� ������ϴ�" << std::endl;
		}
	}


};

void iQueueExample()
{
	std::queue<int> m_q;

	// ť�� �̿��ؼ� 1, 2, 3, 4, 5 ������� �����͸� �ܼ�â�� ���

	m_q.push(1);
	m_q.push(2);
	m_q.push(3);
	m_q.push(4);
	m_q.push(5);
	
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << std::endl;

	// �迭 ��� ť ����
	std::cout << "�迭 ��� ť" << std::endl;
	ArrayBasedQueue<int> myQueue;
	myQueue.Push(1);
	myQueue.Push(2);
	myQueue.Push(3);
	myQueue.Push(4);
	myQueue.Push(5);

	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	myQueue.Print();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << std::endl;

	//������ ����Ʈ ��� ť ����
	std::cout << "������ ����Ʈ ��� ť" << std::endl;
	LinkedQueue<int> linkedQueue;
	linkedQueue.Push(1);
	linkedQueue.Push(2);
	linkedQueue.Push(3);
	linkedQueue.Push(4);
	linkedQueue.Push(5);

	std::cout << "Rear �����Ͱ� ����Ű�� �ִ� �� : " << linkedQueue.Back() << std::endl;
	std::cout << "Front �����Ͱ� ����Ű�� �ִ� �� : " << linkedQueue.Front() << std::endl;
	std::cout << "Queue�� ���� : " << linkedQueue.Size() << std::endl;

	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << std::endl;

	// ���� ť ����
	std::cout << "���� ť ����" << std::endl;
	CircularQueue<int> cQueue;
	cQueue.Push(1);
	cQueue.Push(2);
	cQueue.Push(3);
	cQueue.Push(4);
	cQueue.Push(5);

	std::cout << "Rear �����Ͱ� ����Ű�� �ִ� �� : " << cQueue.Rear() << std::endl;
	std::cout << "Front �����Ͱ� ����Ű�� �ִ� �� : " << cQueue.Front() << std::endl;
	std::cout << "Queue�� ���� ���� : " << cQueue.CurrentSize() << std::endl;
	std::cout << "Queue�� �� ���� : " << cQueue.Size() << std::endl;

	std::cout << cQueue.Front() << std::endl;
	

}

/// <summary>
/// ����ť�� ���� ť�� ������ �����ϱ� ���� ������ �ڷᱸ��
/// ���� ť�� front, Rear�� ��Ȱ���ϱ� �����
/// Pop(Dequeue) : Front = (Front + 1) % �ִ� ��
/// Push(Enqueue) : Rear = (Rear + 1) % �ִ� ��
/// ���� : Front, Rear�߸� ����ϸ� ���ѷ����� ����, ���۰� ���� �ľ��ϱ� ��ƴ�.
/// ��� : ť�� �ݺ��ؼ� ����ؾ� �ϴµ�, �� ������ ���� ���� �� ����ϸ� ����.
/// </summary>

// 1. ���� ť ���� : Front, Rear�� ��� �����ϰ� ��Ȱ���� ����.
// �̸� �����ϱ� ���� ���� ť ����

// 2. ť�� ��뿹�� : �Է¹��� ������� �����͸� ������ �� �ִ�(Ŀ�ǵ带 ���� -> ����)
// �÷��̾��� Ŀ�ǵ带 ����ϴ� ��� ����
// 
// class�� ��� ���� command ����ؼ� ����
// draw.io ���̾�׷� ����
// 
// std::in << input;
// std::<queue> inputs; 
// std::<queue> temp;
// temp.front() ... pop()
// [				]