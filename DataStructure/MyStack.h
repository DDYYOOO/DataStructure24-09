#pragma once
#include<iostream>
/*
  �ڷᱸ�� �����̳� : Array, Array, Vector, Linked List
  
  ���� �����̳ʸ� �����ؼ�(�ڷḦ ����, ����) ����� �����ؼ� ���α׷��� ����ȭ�� ������ �ڷᱸ����.
*/

// Stack �ڷᱸ��
// ���� : ��Ź�� �ٱ��Ͼ� ���� �׾Ƽ� �ѹ��� ��Ź�⿡ �������� �ϸ� ���� ���� �������� ���� �༮���� ��Ź�⿡ ����
// ���� ù��°�� ���� ����(First In) ���� �������� ������.(Last Out) -> FILO
// ���� �������� ���� ����(Last In) ���� ���� ������.(First Out) -> LIFO

// Vector, Linked List, Array �ڷᱸ���� �� ����ϰ� �־��µ�, Stack, Queue, Priority Queue �� ����ұ�?

// ������ ����
// 1. Ŭ���� �����ϱⰡ ����
// 2. LIFO �������, ������� ����
// - �������(Undo) : Ctrl + Z ������ �������� �ʴ´ٸ�... int Count...
// - ���� ǥ��� : �����ϱ� ��. ��ǻ�Ͱ� �б⿡ ���� ǥ���� ���� ǥ���
//   ex) 1+1+2 => 112++

// �迭��� Stack
template<typename T>
class MyArrayStack
{
private:
	T* stackArray;		// stack ������ �����ϱ� ���� �迭
	int capacity;		// ���� �ִ� ũ��
	int top;			// ���� ���� ��ܿ� �ִ� index
public:
	// top�� ����Ű�� index�� "-1" : �����Ͱ� �������� ������ ǥ���ϱ� ���� �� -1
	// top�� ����Ű�� index�� "0"  : ����� ���� ���� �������� ǥ���� �� �ִ�.
	// stackArray�� capacity�� �����Ҵ�
	MyArrayStack(int size)  
	{
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}
	~MyArrayStack()
	{
		// stackArray�� null�� �ƴ� ���� ����
		if (stackArray != nullptr)
			delete[] stackArray;
	}
	// T Ÿ���� newArray �����Ҵ�
	// stackArray �ε��� 0���� top������ �����͸� newArray����
	// ���� stackArray delete[] ���ش�
	// stackArray newArray�� �����ͷ� ���� �Ҵ�
	// this.capacity = _capacity;
	void Resize(int newsize)
	{
		T* newArray = new T[newsize];
		
		for (int i = 0; i < top; i++)
		{
			newArray[i] = stackArray[i];
		}
		delete[] stackArray;

		stackArray = newArray;
		capacity = newsize;
	}
	// top == capacity - 1 : ture or false;
	bool isFull()
	{
		return top == capacity - 1 ? true : false;
	}
	// top ����Ű�� �ִ� ���� "-1" ture or false;
	bool isEmpty()
	{
		return top <= -1 ? true : false;
	}
	// ���� full�̶�� Resize(capacity * 2);
	// stackArray ������ �߰� [top] <-- ������ �߰�
	//top�� 1 ����
	void Push(T data)
	{
		if (isFull())
		{
			Resize(2 * capacity);
		}
		top++;
		stackArray[top] = data;
	}
	// isEmpty() -> ���� ���ÿ� �����Ͱ� ������ϴ� ���
	// return
	// top 1 ����
	void Pop()
	{
		if (isEmpty())
		{
			std::cout << "���� ���ÿ� �����Ͱ� ��������Ƿ� ������ ����� �� �� �����ϴ�.(Stack is UnderFlow)" << std::endl;
			return;
		}
		std::cout << Top() << std::endl;
		--top;
	}

	T Top() const
	{
		return stackArray[top];
	}

	void Clear()
	{
		capacity = 10;
		top = -1;
	}
};

// ������ ����Ʈ ��� Stack

// StackNode  next

// StackNode* pHead

// push

// pop

void StackExample()
{
	MyArrayStack<int> mStack(10);
	mStack.Push(5);
	mStack.Push(4);
	mStack.Push(3);
	mStack.Push(2);
	mStack.Push(1);

	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
}
