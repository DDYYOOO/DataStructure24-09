#pragma once
#include<iostream>
#include<vector>

// ������ ����

// int abc;
// int* intptr = &abc;
// ������ ������ : *intptr, intptr++, ++intptr, intptr == , intptr !=
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
		//���� ������ ++it
		iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// ���� ������ it++
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
// iterator ���� ���� �Լ�
public:
	using iterator = iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + size; }
// Container �ڷᱸ���� ��� ����
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
		size = size > 0 ? size - 1 : 0;		// 1. size > 0 �� true -> (size -1)����, false -> 0 ����� size ����
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

	std::cout << "iterator�� ����� �ݺ� �����" << std::endl;
	
	auto it = vec.begin();

	for (it; it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// for�ݺ��� : range based for loop
	std::cout << "���� ��� ���� �����" << std::endl;

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
