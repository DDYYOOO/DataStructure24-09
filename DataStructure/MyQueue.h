#pragma once
#include<iostream>
#include<queue>

/*
  자료구조 : 컨테이너를 변형해서 순서를 정해두고 사용하는 어뎁터 자료구조
  자료구조의 데이터를 저장할 때 먼저 들어간 자료가 먼저 나오는 형태의 자료구조
  ex) 대기표를 끊는다 -> 사람들이 줄을 선다 -> 먼저 온 사람이 먼저 대기표를 끊는다 -> 가장 마지막에 온 사람은 가장 마지막에 처리한다

  큐 자료구조 구현
  - 데이터가 출력되는 인덱스를 front이름으로 표현
  - 데이터가 저장되는 인덱스를 rear이름으로 표현
  - 선형 큐 front rear 초기값으로 되돌아 갈 수 없다.


*/

// 구현해야할 함수
// 입력 및 삭제 : push, pop 
// 필드 값 표현 : empty(), size(), front(), back()

template<typename T>
class ArrayBasedQueue
{
private:
	T* queue;		// 데이터를 저장하기 위한 배열 이름
	int front;		// 출력 위치를 가리키는 인덱스
	int rear;		// 입력 위치를 가리키는 인덱스
	int iCount;		// 현재 자료구조의 원소의 갯수
public:
	// 생성자, 소멸자
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

	// Accesor : 필드에 접근을 위한 함수
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

	// Main Method : 삽입, 삭제
	void Push(T data)
	{
		queue[rear] = data;		// queue 배열 data 삽입
		rear++;					// rear 증가, 변경
		iCount++;				// 갯수 증가
	}
	void Pop()
	{
		if (iCount != 0)// queue 비어있지 않았을 때
		{
			front++;			// queue 배열 front 변경
			iCount--;			// 갯수 감수	
		}
		else
		{
			std::cout << "큐가 비었습니다" << std::endl;
		}
	}

	void Print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}
};

// 다른 클래스에서도 Node를 쓸 때 따로 구조체 선언(범용성)
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
	// 생성자, 소멸자
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

	// Main Method(입력, 삭제)
	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);		// newNode 동적할당
		//QueueNode* newNode = new QueueNode;		// 위 코드와 같은 코드
		//newNode->data = data;
		//newNode->pNext = nullptr;
		
		if (Empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->pNext = newNode;	// 마지막 포인터의 다음 포인터에 새로 할당한 노드를 넣어준다
			rear = newNode;			// 새로운 노드를 rear로 재지정해준다.
		}
		
		iCount++;
	}
	void Pop()
	{
		if (Empty())
		{
			std::cout << "큐가 비었습니다" << std::endl;
			return;
		}
		
		QueueNode* oldNode = front;		// 삭제할 노드를 복사
		front = front->pNext;			// 기존의 front노드의 다음 노드를 front로 변경
		delete oldNode;
		iCount--;

	}
};

template<typename T>
class CircularQueue
{
	// 배열 기반 원형 큐
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
			std::cout << "큐가 비었습니다" << std::endl;
		}
	}


};

void iQueueExample()
{
	std::queue<int> m_q;

	// 큐를 이용해서 1, 2, 3, 4, 5 순서대로 데이터를 콘솔창에 출력

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

	// 배열 기반 큐 선언
	std::cout << "배열 기반 큐" << std::endl;
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

	//연결형 리스트 기반 큐 선언
	std::cout << "연결형 리스트 기반 큐" << std::endl;
	LinkedQueue<int> linkedQueue;
	linkedQueue.Push(1);
	linkedQueue.Push(2);
	linkedQueue.Push(3);
	linkedQueue.Push(4);
	linkedQueue.Push(5);

	std::cout << "Rear 포인터가 가리키고 있는 값 : " << linkedQueue.Back() << std::endl;
	std::cout << "Front 포인터가 가리키고 있는 값 : " << linkedQueue.Front() << std::endl;
	std::cout << "Queue의 갯수 : " << linkedQueue.Size() << std::endl;

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

	// 원형 큐 선언
	std::cout << "원형 큐 선언" << std::endl;
	CircularQueue<int> cQueue;
	cQueue.Push(1);
	cQueue.Push(2);
	cQueue.Push(3);
	cQueue.Push(4);
	cQueue.Push(5);

	std::cout << "Rear 포인터가 가리키고 있는 값 : " << cQueue.Rear() << std::endl;
	std::cout << "Front 포인터가 가리키고 있는 값 : " << cQueue.Front() << std::endl;
	std::cout << "Queue의 현재 갯수 : " << cQueue.CurrentSize() << std::endl;
	std::cout << "Queue의 총 갯수 : " << cQueue.Size() << std::endl;

	std::cout << cQueue.Front() << std::endl;
	

}

/// <summary>
/// 원형큐는 선형 큐의 단점을 개선하기 위해 등장한 자료구조
/// 선형 큐는 front, Rear을 재활용하기 힘들다
/// Pop(Dequeue) : Front = (Front + 1) % 최대 값
/// Push(Enqueue) : Rear = (Rear + 1) % 최대 값
/// 단점 : Front, Rear잘못 사용하면 무한루프에 빠짐, 시작과 끝을 파악하기 어렵다.
/// 사용 : 큐를 반복해서 사용해야 하는데, 그 갯수가 많지 않을 때 사용하면 좋다.
/// </summary>

// 1. 선형 큐 단점 : Front, Rear가 계속 증가하고 재활용이 힘듦.
// 이를 개선하기 위한 원형 큐 구현

// 2. 큐의 사용예시 : 입력받은 순서대로 데이터를 저장할 수 있다(커맨드를 저장 -> 실행)
// 플레이어의 커맨드를 출력하는 기능 구현
// 
// class의 상속 관계 command 상속해서 구현
// draw.io 다이어그램 구상
// 
// std::in << input;
// std::<queue> inputs; 
// std::<queue> temp;
// temp.front() ... pop()
// [				]