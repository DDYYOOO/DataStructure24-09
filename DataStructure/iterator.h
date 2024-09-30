#pragma once
#include<iostream>
#include<vector>

// 포인터 사용법

// int abc;
// int* intptr = &abc;
// 포인터 연산자 : *intptr, intptr++, ++intptr, intptr == , intptr !=
// 

template<typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class iterator
	{
	private:
		T* ptr;
	public:
		iterator() : ptr(nullptr) {}
		iterator(T* _ptr) : ptr(ptr) {}

		T& operator*()
		{
			return *ptr;
		}
		//전위 연산자 ++it
		iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// 후위 연산자 it++
		iterator& operator++(int)
		{
			iterator temp = this;
			ptr++;
			return temp;
		}

		bool operator==(const iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const iterator& other)
		{
			return ptr != other.ptr;
		}

		iterator operator+(const int count)
		{

		}
	};
// iterator 공개 허용된 함수
public:
	using iterator = iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + size; }
// Container 자료구조의 기능 구현
public:
	Container(int _size = 3)
	{
		arr = new T[_size];
		size = 0;
		capacity = 0;
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

	//auto it = myCon.begin();
}
