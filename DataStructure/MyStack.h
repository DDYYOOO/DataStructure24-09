#pragma once
#include<iostream>
/*
  자료구조 컨테이너 : Array, Array, Vector, Linked List
  
  기존 컨테이너를 변형해서(자료를 삽입, 삭제) 기능을 제한해서 프로그래밍 최적화를 구현한 자료구조다.
*/

// Stack 자료구조
// 예시 : 세탁용 바구니아 옷을 쌓아서 한번에 세탁기에 넣을려고 하면 옷은 가장 마지막에 쌓인 녀석부터 세탁기에 들어간다
// 가장 첫번째로 들어온 것이(First In) 가장 마지막에 나간다.(Last Out) -> FILO
// 가장 마지막에 들어온 것이(Last In) 가장 먼저 나간다.(First Out) -> LIFO

// Vector, Linked List, Array 자료구조를 잘 사용하고 있었는데, Stack, Queue, Priority Queue 왜 사용할까?

// 스택의 장점
// 1. 클래스 구현하기가 쉽다
// 2. LIFO 방식으로, 순서대로 저장
// - 실행취소(Undo) : Ctrl + Z 스택을 구현하지 않는다면... int Count...
// - 후위 표기법 : 구현하기 편리. 컴퓨터가 읽기에 쉽게 표현된 연산 표기법
//   ex) 1+1+2 => 112++

// 배열기반 Stack
template<typename T>
class MyArrayStack
{
private:
	T* stackArray;		// stack 데이터 저장하기 위한 배열
	int capacity;		// 스택 최대 크기
	int top;			// 현재 가장 산단에 있는 index
public:
	// top이 가리키는 index를 "-1" : 데이터가 생성되지 않음을 표현하기 위한 수 -1
	// top이 가리키는 index를 "0"  : 사람이 세는 수의 시작으로 표현할 수 있다.
	// stackArray를 capacity로 동적할당
	MyArrayStack(int size)  
	{
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}
	~MyArrayStack()
	{
		// stackArray가 null이 아닐 때만 삭제
		if (stackArray != nullptr)
			delete[] stackArray;
	}
	// T 타입을 newArray 동적할당
	// stackArray 인덱스 0부터 top까지의 데이터를 newArray저장
	// 기존 stackArray delete[] 해준다
	// stackArray newArray의 데이터로 새로 할당
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
	// top 가리키고 있는 값이 "-1" ture or false;
	bool isEmpty()
	{
		return top <= -1 ? true : false;
	}
	// 만약 full이라면 Resize(capacity * 2);
	// stackArray 데이터 추가 [top] <-- 데이터 추가
	//top을 1 증가
	void Push(T data)
	{
		if (isFull())
		{
			Resize(2 * capacity);
		}
		top++;
		stackArray[top] = data;
	}
	// isEmpty() -> 현재 스택에 데이터가 비었습니다 출력
	// return
	// top 1 감소
	void Pop()
	{
		if (isEmpty())
		{
			std::cout << "현재 스택에 데이터가 비어있으므로 데이터 출력을 할 수 없습니다.(Stack is UnderFlow)" << std::endl;
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

// 연결형 리스트 기반 Stack

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
