#include "LinkedList.h"

ILinkedList::ILinkedList()
{

}

ILinkedList::~ILinkedList()
{

}

void ILinkedList::PushFront(const int& data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = data;

	if (nullptr == pHead)		// Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��
	{
		// Head �����͸� ���ο� ���� ����
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = pHead; // ���ο� ����� Next �ּҸ� head�� ����Ű���� �ۼ�
		pHead = pNewNode;		 // ���� head�� ���ο� ���� ����
	}

	++iCount; // �ڷᱸ���� ����ִ� �������� �� ����
}

void ILinkedList::PushBack(const int& data)
{
	IntNode* pLastNode = new IntNode;
	pLastNode->value = data;
	// �����Ͱ� ó�� �� �� ����
	if (nullptr == pHead)
	{
		pHead = pLastNode;
		pTail = pLastNode;
	}
	// tail�� ���� �ּҿ� ��带 ����
	pTail->pPrev = pLastNode;		// ������ ���� �����Ͱ� ������ ��尡 �ȴ�
	pTail = pLastNode;				// ���� head�� ���ο� ���� ����

	++iCount;
}

void ILinkedList::RemoveFront()
{
	if (nullptr == pHead)		// bool isEmpty()
	{
		std::cout << "�����Ͱ� �����Ƿ� ������ ����մϴ�." << std::endl;
		return;
	}
	
	IntNode* pOldNode = pHead;			// pHead �ӽ� �����͸� ����
	
	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pHead->pNext;			// pHead->pNext : head�� �����
	}
	delete pOldNode;					// pOldNode �޸𸮸� ��ü

	--iCount;

}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead)
	{
		std::cout << "�����Ͱ� �����Ƿ� ������ ����մϴ�." << std::endl;
		return;
	}

	IntNode* pOldNode = pTail;

	if (nullptr == pOldNode->pPrev)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pTail->pPrev = pTail;
	}
	delete pOldNode;

	--iCount;
}

void ILinkedList::FrontValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << ", ù��° ������ �� : " << pHead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << ", ������ ������ �� : " << pTail->value << std::endl;
}
