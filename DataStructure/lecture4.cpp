#include"lectures.h"
#include<iostream>
#include<list>
#include<string>

// ���� ����Ʈ : std::list template

// ���� ������ - �߰�, ���� <- �κ��丮
// �迭 - ���� ����Ʈ
// ���� : ������ ������ ������ ������ <-> ������ ������ ������ �Ұ����ϴ�
// ���� : ������ ���� �� �߰��� ������ <-> ������ ���� �� �߰��� ������


class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemcode, std::string _name) : itemCode(_itemcode), name(_name) {}
	
	void ShowInfo()
	{
		std::cout << "������ �ڵ� : " << itemCode << std::endl;
		std::cout << "������ �̸� : " << name << std::endl;
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
		std::cout << "������ �̸� : " << myPos.ReturnTag() << std::endl;
		//std::cout << "X, Y ��ǥ �� : " << X << ", " << Y << std::endl;
	}


};

void lecture4()
{
	std::cout << "STL : ���� ����Ʈ ���" << std::endl;

	// ���� �Ҵ�
	//std::list<int>* iList = new std::list<int>();

	//std::list<int> iList; // Ŭ���� ����
	std::list<Item> inventory;

	// ������ ���� 
	// PushFront == push_front
	// PushBack == push_back
	// ������ ���� 
	// RemoveFront == pop_front
	// RemoveBack == pop_back

	Item* newItem = new Item(1001, "���");
	Item* newItem2 = new Item(1002, "�Ѽհ�");
	Item* newItem3 = new Item(1003, "�ظ�");

	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);

	std::list<Item>::iterator iPos = inventory.begin();
	inventory.insert(iPos, 1, *newItem3);

	inventory.pop_back();

	// iterator : �����͸� �Ϲ�ȭ��Ų Ŭ����
	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd; iterPos++)
	{
		iterPos->ShowInfo();
	}

	// Ŭ���� ����

	// list, LinkedList.h - int, DoubliyLinkedList.h - string

	// LinkedList<int> iList1;
	// std::list<int> iList2;
	

	// DoubliyLinkedList dList1;
	// std::list<string> dList2;

	// ���� ����
	// ������ Ŭ������ ����
	// A(50, 200), B(20, 80), C(75, 10), D(30, 80), E(100, 200)
	// class Pos(posX, posY)
	// Pos value�� ����, node�� ������

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
