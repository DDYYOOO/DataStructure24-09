#pragma once
#include<iostream>
#include<vector>
#include<deque>
#include<string>
/*
	Vector�� Deque �� ����
	Vector 
	- ������ ���� �����ϴ� �ð� O(1)
	- �ڿ������� ���Ҹ� ������ �� ȿ���� O(1)
	- �߰��� ���Ҹ� ����, ���� �ϴ� �ð��� ������ O(n)		- Node��� �����ϸ� O(1)

	Deque
	- ������ ���� �����ϴ� �ð� O(1)
	- �ڿ������� ���Ҹ� ������ �� ȿ���� O(1)
	- �߰��� ���Ҹ� ����, ���� �ϴ� �ð��� ������ O(n)		- Node��� �����ϸ� O(1)
*/

template<typename T>
class MyDeque
{
private:
	std::vector<T*> blocks;		// �� ����� �����ϴ� �ڷᱸ��  - �񿬼����� �޸� ���� ���
	int blockSize;				// ����� �ִ�� ������ �� �ִ� ũ��
	int frontIndex;				// ù��° ����� �ε��� 
	int backIndex;				// ������ ����� �ε���
	int iCount;					// ���� Deque ����� ������ ����

	void allocateBlock()		// ��� ���� �Լ�
	{
		blocks.push_back(new T(blockSize));		// new T(blockSize) -> vector<T*> blocks�� push_back
	}
	void addFrontBlock()		// ���� ��� �߰�
	{
		blocks.insert(blocks.begin(), new T(blockSize));
		frontIndex = blockSize - 1;
	}
	void addBackBlock()			// ���� ��� �߰�
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// ����, �Ҹ���
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
			throw std::out_of_range("���� ������ϴ�");
		}
		return blocks[0][frontIndex + 1];
	}
	T& GetBack() const
	{
		if (isEmpty())
		{
			throw std::out_of_range("���� ������ϴ�");
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
			std::cout << "���� ������ϴ�." << std::endl;
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
			std::cout << "���� ������ϴ�." << std::endl;
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

	std::cout << "�Ӹ� : " << M_Deq.GetFront() << std::endl;
	std::cout << "���� : " << M_Deq.GetBack() << std::endl;

	M_Deq.PopBack();
	M_Deq.PopFront();

	std::cout << "�Ӹ� : " << M_Deq.GetFront() << std::endl;
	std::cout << "���� : " << M_Deq.GetBack() << std::endl;

	
}