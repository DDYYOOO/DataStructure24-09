#pragma once
#include<iostream>
#include<vector>
#include<string>

// 포인터 사용법

// int abc;
// int* intptr = &abc;
// 포인터 연산자 : *intptr, intptr++, ++intptr, intptr == , intptr !=

// class Item -> inventory 자료구조 -> std::vector<float>... Item.Print(), 포인터 

// vector<Item> inventory

class Item
{
private:
	float time;
	int idx;
public:
	Item() {}
	Item(float _time, int _idx) : time(_time), idx(_idx) {}
	void Print()
	{
		std::cout << "NO." << idx << " 아이템 이름 : " << time << std::endl;
	}
};

template<typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class Iterator
	{
	private:
		T* ptr;
	public:
		Iterator() : ptr(nullptr) {}
		Iterator(T* _ptr) : ptr(_ptr) {}

		T& operator*()
		{
			return *ptr;
		}
		//전위 연산자 ++it
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// 후위 연산자 it++
		Iterator& operator++(int)
		{
			Iterator temp = *this;
			ptr++;
			return temp;
		}

		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr;
		}

		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}
	};
// iterator 공개 허용된 함수
public:
	using iterator = Iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + size; }
// Container 자료구조의 기능 구현
public:
	Container(int _size = 3)
	{
		arr = new T[_size];
		size = 0;
		capacity = _size;
	}

	void push_back(T data)
	{
		arr[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;		// 1. size > 0 비교 true -> (size -1)실행, false -> 0 결과물 size 대입
	}

	//int size() { return size; }
};


void IteratorExample()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	std::cout << "iterator로 출력한 반복 결과문" << std::endl;
	
	auto it = vec.begin();

	for (it; it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// for반복문 : range based for loop
	std::cout << "범위 기반 루프 결과문" << std::endl;

	for (int elem : vec)
	{
		std::cout << elem << std::endl;
	}

	Container<int> myCon;
	
	myCon.push_back(10);
	myCon.push_back(20);
	myCon.push_back(30);

	/*Container<int>::iterator == auto*/ 
	auto myIt = myCon.begin();

	for (myIt; myIt != myCon.end(); myIt++)
	{
		std::cout << "Iterator로 출력한 데이터 결과문" << *myIt << std::endl;
	}

	// range base for loop
	// 범위 기반 for 반복문
	for (int& elem : myCon)
	{
		elem += 100;
		std::cout << "범위 기반 결과문" << elem << std::endl;
	}

	myIt = myCon.begin();

	for (myIt; myIt != myCon.end(); myIt++)
	{
		std::cout << "Iterator로 출력한 데이터 결과문" << *myIt << std::endl;
	}

	// auto : 자동으로 뒤에 있는 변수의 타입을 지정해준다
	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	std::cout << a << "," << b << "," << c << "," << d << "," << std::endl;

	std::cout << "Item Class 사용 예시" << std::endl;

	Container<Item> inventory;

	Item item1(12.345, 1);
	Item item2(32.167, 1);

	inventory.push_back(item1);
	inventory.push_back(item2);

	Container<Item>::iterator itemIt = inventory.begin();

	// iterator for 반복문
	std::cout << "Item Iterator를 이용한 반복문" << std::endl;

	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}

}
