#include"lectures.h"
#include"DoubliyLinkedList.h"


void lecture3()
{
	DoubliyLinkedList dList;

	dList.PushFront("문자1");
	dList.PushBack("문자2");
	dList.Insert(1, "문자1-2");
	dList.Insert(1, "문자1-1");
	//dList.RemoveBack();

	dList.Print();
}