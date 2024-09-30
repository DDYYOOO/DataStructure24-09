#pragma once
#include<iostream>
#include<vector>
#include<deque>
#include<string>
/*
	Vector와 Deque 비교 설명
	Vector 
	- 임의의 원소 접근하는 시간 O(1)
	- 뒤에서부터 원소를 삽입할 때 효율적 O(1)
	- 중간의 원소를 삽입, 삭제 하는 시간이 느리다 O(n)		- Node기반 구현하면 O(1)

	Deque
	- 임의의 원소 접근하는 시간 O(1)
	- 뒤에서부터 원소를 삽입할 때 효율적 O(1)
	- 중간의 원소를 삽입, 삭제 하는 시간이 느리다 O(n)		- Node기반 구현하면 O(1)
*/

template<typename T>
class MyDeque
{
private:
	std::vector<T*> blocks;		// 각 블록을 저장하는 자료구조  - 비연속적인 메모리 관리 방식
	int blockSize;				// 블록이 최대로 저장할 수 있는 크기
	int frontIndex;				// 첫번째 블록의 인덱스 
	int backIndex;				// 마지막 블록의 인덱스
	int iCount;					// 현재 Deque 저장된 원소의 갯수

	void allocateBlock()		// 블록 생성 함수
	{
		blocks.push_back(new T(blockSize));		// new T(blockSize) -> vector<T*> blocks에 push_back
	}
	void addFrontBlock()		// 앞쪽 블록 추가
	{
		blocks.insert(blocks.begin(), new T(blockSize));
		frontIndex = blockSize - 1;
	}
	void addBackBlock()			// 뒤쪽 블록 추가
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// 생성, 소멸자
	MyDeque(int blocksize = 4) : blockSize(blocksize), frontIndex(0), backIndex(0), iCount(0) 
	{
		allocateBlock();
	}
	~MyDeque() 
	{
		for (T* block : blocks)
		{
			delete[] block;
		}
	}

	// Accessor
	int GetSize() const { return iCount; }
	bool isEmpty() const { return iCount == 0 ? true : false; }
	T& GetFront() const
	{
		if (isEmpty())
		{
			throw std::out_of_range("덱이 비었습니다");
		}
		return blocks[0][frontIndex + 1];
	}
	T& GetBack() const
	{
		if (isEmpty())
		{
			throw std::out_of_range("덱이 비었습니다");
		}
		return blocks.back()[backIndex - 1];
	}

	// Main Method
	void PushFront(const T& data)	
	{
		if (frontIndex < 0)
		{
			addFrontBlock();
		}
		blocks[0][frontIndex--] = data;
		++iCount;
	}
	void PushBack(const T& data)
	{
		if (backIndex == blockSize)
		{
			addBackBlock();
		}
		blocks.back()[backIndex++] = data;
		++iCount;
	}
	void PopFront()
	{
		if (isEmpty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		++frontIndex;
		--iCount;

		if (frontIndex == blockSize)
		{
			delete[] blocks.front();
			blocks.erase(blocks.begin());
			frontIndex = 0;
 		}
	}
	void PopBack()
	{
		if (isEmpty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		--backIndex;
		--iCount;

		if (backIndex < 0)
		{
			delete[] blocks.back();
			backIndex = blockSize - 1;
		}
	}
};

void IDequeExample()
{
	MyDeque<int> M_Deq;
	
	// main method

	M_Deq.PushBack(10);
	M_Deq.PushBack(20);
	M_Deq.PushBack(30);
	M_Deq.PushFront(5);
	M_Deq.PushFront(1);

	std::cout << "머리 : " << M_Deq.GetFront() << std::endl;
	std::cout << "꼬리 : " << M_Deq.GetBack() << std::endl;

	M_Deq.PopBack();
	M_Deq.PopFront();

	std::cout << "머리 : " << M_Deq.GetFront() << std::endl;
	std::cout << "꼬리 : " << M_Deq.GetBack() << std::endl;

	
}