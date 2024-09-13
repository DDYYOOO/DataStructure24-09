#include"lectures.h"
#include<iostream>
#include<list>
#include<string>

// 연결 리스트 : std::list template

// 게임 아이템 - 추가, 삭제 <- 인벤토리
// 배열 - 연결 리스트
// 장점 : 임의의 원소의 접근이 빠르다 <-> 임의의 원소의 접근이 불가능하다
// 단점 : 데이터 삭제 및 추가가 느리다 <-> 데이터 삭제 및 추가가 빠르다


class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemcode, std::string _name) : itemCode(_itemcode), name(_name) {}
	
	void ShowInfo()
	{
		std::cout << "아이템 코드 : " << itemCode << std::endl;
		std::cout << "아이템 이름 : " << name << std::endl;
	}
};

template<typename T>
class Node
{
private:
	T value;
	Node* next;
};

template<typename T>
class LinkedList
{

};

class Pos
{
private:
	char tag;
	int posX;
	int posY;
public:
	Pos() {}
	Pos(char _tag, int x, int y) : tag(_tag), posX(x), posY(y) {}

	char ReturnTag() { return tag; }
	int ReturnPosX() { return posX; }
	int ReturnPosY() { return posY; }
};

class Point
{
private:

public:
	Pos data;
	Point* next;
	Point(Pos _data) : data(_data) {}
};

class Star 
{
private:
	Pos myPos;
public:
	Star() {}

	void ShowInfo()
	{
		std::cout << "꼭지점 이름 : " << myPos.ReturnTag() << std::endl;
		//std::cout << "X, Y 좌표 값 : " << X << ", " << Y << std::endl;
	}


};

void lecture4()
{
	std::cout << "STL : 연결 리스트 사용" << std::endl;

	// 동적 할당
	//std::list<int>* iList = new std::list<int>();

	//std::list<int> iList; // 클래스 생성
	std::list<Item> inventory;

	// 데이터 저장 
	// PushFront == push_front
	// PushBack == push_back
	// 데이터 삭제 
	// RemoveFront == pop_front
	// RemoveBack == pop_back

	Item* newItem = new Item(1001, "대검");
	Item* newItem2 = new Item(1002, "한손검");
	Item* newItem3 = new Item(1003, "해머");

	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);

	std::list<Item>::iterator iPos = inventory.begin();
	inventory.insert(iPos, 1, *newItem3);

	inventory.pop_back();

	// iterator : 포인터를 일반화시킨 클래스
	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd; iterPos++)
	{
		iterPos->ShowInfo();
	}

	// 클래스 구현

	// list, LinkedList.h - int, DoubliyLinkedList.h - string

	// LinkedList<int> iList1;
	// std::list<int> iList2;
	

	// DoubliyLinkedList dList1;
	// std::list<string> dList2;

	// 예제 문제
	// 도형을 클래스로 정의
	// A(50, 200), B(20, 80), C(75, 10), D(30, 80), E(100, 200)
	// class Pos(posX, posY)
	// Pos value로 갖는, node를 재정의

	Pos A = Pos('A', 50, 200);
	Pos B = Pos('B', 20, 80);
	Pos C = Pos('C', 75, 10);
	Pos D = Pos('D', 30, 80);
	Pos E = Pos('E', 100, 200);

	// (1)
	std::list<Pos> Star;

	Star.push_back(A);
	Star.push_back(B);
	Star.push_back(C);
	Star.push_back(D);
	Star.push_back(E);

	// (2)
	Point A_P = Point(A);
	Point B_P = Point(B);
	Point C_P = Point(C);
	Point D_P = Point(D);
	Point E_P = Point(E);

	A_P.next = &B_P;
	B_P.next = &C_P;
	C_P.next = &D_P;
	D_P.next = &E_P;

}
