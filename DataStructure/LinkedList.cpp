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

	if (nullptr == pHead)		// Head가 가르키고 있는 포인터 null 비어있는 자료구조
	{
		// Head 포인터를 새로운 노드로 변경
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = pHead; // 새로운 노드의 Next 주소를 head를 가리키도록 작성
		pHead = pNewNode;		 // 기존 head를 새로운 노드로 변경
	}

	++iCount; // 자료구조에 들어있는 데이터의 총 갯수
}

void ILinkedList::PushBack(const int& data)
{
	IntNode* pLastNode = new IntNode;
	pLastNode->value = data;
	// 데이터가 처음 들어갈 때 조건
	if (nullptr == pHead)
	{
		pHead = pLastNode;
		pTail = pLastNode;
	}
	// tail의 다음 주소에 노드를 생성
	pTail->pPrev = pLastNode;		// 꼬리의 다음 포인터가 새로은 노드가 된다
	pTail = pLastNode;				// 기존 head를 새로운 노드로 변경

	++iCount;
}

void ILinkedList::RemoveFront()
{
	if (nullptr == pHead)		// bool isEmpty()
	{
		std::cout << "데이터가 없으므로 실행을 취소합니다." << std::endl;
		return;
	}
	
	IntNode* pOldNode = pHead;			// pHead 임시 데이터를 생성
	
	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pHead->pNext;			// pHead->pNext : head로 만든다
	}
	delete pOldNode;					// pOldNode 메모리를 해체

	--iCount;

}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead)
	{
		std::cout << "데이터가 없으므로 실행을 취소합니다." << std::endl;
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
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << ", 첫번째 원소의 값 : " << pHead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << ", 마지막 원소의 값 : " << pTail->value << std::endl;
}
