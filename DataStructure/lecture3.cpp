#include"lectures.h"
#include"DoubliyLinkedList.h"


void lecture3()
{
	DoubliyLinkedList dList;

	dList.PushFront("����1");
	dList.PushBack("����2");
	dList.Insert(1, "����1-2");
	dList.Insert(1, "����1-1");
	//dList.RemoveBack();

	dList.Print();
}