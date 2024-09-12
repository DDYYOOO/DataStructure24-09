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
	newNode->pPrev = nullptr; // ���ο� ����� prev�� ����־���Ѵ�.
	newNode->pNext = pHead;   // ���ο� ����� next ������ head�����Ѵ�.
	pHead = newNode;		  // ���ο� �Ӹ��� ���ο� ���� ����

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
	newNode->pPrev = pTail;				// ���ο� ����� prev�� ����־���Ѵ�.
	newNode->pNext = nullptr;			// ���ο� ����� next ������ tail�����Ѵ�.
	pTail->pNext = newNode;	// ���ο� ����� ���� ����� ���� ��尡 newNode
	pTail = newNode;					// ���ο� ������ ���ο� ���� ����

	iCount++;
}

void DoubliyLinkedList::PushMiddle(int index, const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	StringNode* curNode = pHead;

	// index�� n��°��� ����

	int i = 0;
	while (i < index - 1)
	{
		curNode = curNode->pNext;				//curNode = pHead->pNext;
		i++;									//curNode = pHead->pNext->pNext;
												//newNode = pHead->pNext->pNext.....
	}

	newNode->pPrev = curNode;			// ���ο� ����� ���� : ���� ���
	newNode->pNext = curNode->pNext;	// ���ο� ����� ���� : ���� ����� next ���
	curNode->pNext->pPrev = newNode;	// ���� ����� ���� : ���ο� ���
	curNode->pNext = newNode;			// ���� ����� ���� ��尡 ����Ű�� �ִ� ���� : ���ο� ���

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// iCount 0���� ������ 
	if (index < 0 || index >= iCount)
	{
		cout << "index�������� ���" << endl;	// index ���� �߻�
		return;
	}
	else if (index == 0)
	{
		PushFront(_data);				// index = 0 (PushFront �Լ� ����)
	}
	else if (index == iCount)
	{
		PushBack(_data);				// index = iCount - 1 (PushBack �Լ� ����)
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

		if (nullptr == remove->pNext)		// pHead->pNext null�� 1���� ����
		{
			pHead = pTail = nullptr;
		}
		else                                // �ƴ� �� 
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
