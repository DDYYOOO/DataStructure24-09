#include "DoubliyLinkedList.h"

void DoubliyLinkedList::PushFront(const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)
	{
		pHead = newNode;
		pTail = newNode;
	}
	newNode->pPrev = nullptr; // 새로운 노드의 prev는 비어있어야한다.
	newNode->pNext = pHead;   // 새로운 노드의 next 기존의 head여야한다.
	pHead = newNode;		  // 새로운 머리를 새로운 노드로 변경

	iCount++;
}

void DoubliyLinkedList::PushBack(const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)
	{
		pHead = newNode;
		pTail = newNode;
	}
	newNode->pPrev = pTail;				// 새로운 노드의 prev는 비어있어야한다.
	newNode->pNext = nullptr;			// 새로운 노드의 next 기존의 tail여야한다.
	pTail->pNext = newNode;	// 새로운 노드의 이전 노드의 다음 노드가 newNode
	pTail = newNode;					// 새로운 꼬리를 새로운 노드로 변경

	iCount++;
}

void DoubliyLinkedList::PushMiddle(int index, const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	StringNode* curNode = pHead;

	// index가 n번째라고 가정

	int i = 0;
	while (i < index - 1)
	{
		curNode = curNode->pNext;				//curNode = pHead->pNext;
		i++;									//curNode = pHead->pNext->pNext;
												//newNode = pHead->pNext->pNext.....
	}

	newNode->pPrev = curNode;			// 새로운 노드의 이전 : 기존 노드
	newNode->pNext = curNode->pNext;	// 새로운 노드의 이후 : 기존 노드의 next 노드
	curNode->pNext->pPrev = newNode;	// 기존 노드의 이후 : 새로운 노드
	curNode->pNext = newNode;			// 기존 노드의 이후 노드가 가리키고 있던 이전 : 새로운 노드

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// iCount 0보다 작으면 
	if (index < 0 || index >= iCount)
	{
		cout << "index범위에서 벗어남" << endl;	// index 에러 발생
		return;
	}
	else if (index == 0)
	{
		PushFront(_data);				// index = 0 (PushFront 함수 실행)
	}
	else if (index == iCount)
	{
		PushBack(_data);				// index = iCount - 1 (PushBack 함수 실행)
	}
	else
	{
		PushMiddle(index, _data);
	}

	// Node -> newNode -> Node
}

void DoubliyLinkedList::Print()
{
	StringNode* printNode = pHead;

	while (printNode != nullptr)
	{
		if (printNode->pNext == nullptr)
		{
			cout << printNode->value << endl;
		}
		else
		{
			cout << printNode->value << " " << "<->" << " ";
		}

		printNode = printNode->pNext;
	}
}

void DoubliyLinkedList::RemoveFront()
{
	if (nullptr != pHead)
	{
		StringNode* remove = pHead;

		if (nullptr == remove->pNext)		// pHead->pNext null이 1개만 존재
		{
			pHead = pTail = nullptr;
		}
		else                                // 아닐 때 
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete remove;
		}
		iCount--;
	}
}

void DoubliyLinkedList::RemoveBack()
{
	if (nullptr != pTail)
	{
		StringNode* remove = pTail;

		if (nullptr == remove->pPrev)
		{
			pTail = pHead = nullptr;
		}
		else
		{
			pTail = pTail->pPrev;
			pTail->pNext = nullptr;
			delete remove;
		}
		iCount--;
	}
}

void DoubliyLinkedList::RemoveAt(int index)
{
	
}
