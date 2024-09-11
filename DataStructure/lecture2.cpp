#include"lectures.h"
#include"LinkedList.h"

void lecture2()
{
	ILinkedList iList;

	iList.PushFront(10);
	iList.FrontValue();

	iList.PushFront(5);
	iList.RemoveFront();
	iList.FrontValue();
	
	iList.PushBack(15);
	iList.TailValue();
	iList.RemoveBack();
	iList.TailValue();
}
