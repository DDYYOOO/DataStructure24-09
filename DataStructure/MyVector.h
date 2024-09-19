#pragma once

#include<iostream>
#include<string>

// 배열 : 크기가 고정되어 있었다
// ADT
// 배열의 길이를 바꿀 수 있는 클래스로 만듦
// 배열의 전체 길이 Capacity
// 현재 배열의 담긴 원소 수 : size
// push_back() => size++; 조건 : Capacity <= size -> 최대 용량을 늘려준다(알고리즘)

template<typename T>
class MyVector
{
private:
	T* vec;			// 원소를 담을 시작 주소
	int size;			// 원소의 현재 담겨 있는 크기
	int capacity;		// 최대로 담을 수 있는 크기	
public:
	// 생성자
	MyVector(int temp = 10)	// 클래스를 생성할 때 int 값을 인자로 넘겨주지 않으면 10 크기가 자동으로 할당
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;		
	}
	// 소멸자
	~MyVector()
	{
		delete[] vec;
	}
	// 연산자 오버로딩 [], ==, !=
	T& operator[](int index)	// 배열의 index에 접근하는 기능 구현
	{
		return vec[index];
	}
	
	bool operator==(MyVector& other)
	{
		if (size != other.size)// 현재 자료구조의 원소 갯수랑 other 원소 갯수 비교
			return false;		// 다르다.

		if (capacity != other.capacity)		// custom : 최대 용량 수가 다르면 다른 것으로 간주
			return false;
		
		for (int i = 0; i < size; i++)
		{
			if (vec[i] != other[i])
				return false;
		}
		return true;

	}

	bool operator!=(MyVector& other)
	{
		return !(*this == other);
	}
	
	// 원소 추가, 삭제
	// 새롭게 배열을 할당하는 작업이 적을수록 시간이 적게 걸린다
	void ResizeVector(int newSize)		// ※ 배열의 크기가 증가하는 case만 Resize해준다
	{
		// 1. 동적 할당 : new키워드 capacity 크기 만큼 T타입의 데이터 배열을 만든다.
		T* newVec = new T[newSize];
		// 2. 새로 만든 배열에 기존 배열에 대입
		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		if (capacity <= size)		// 최대 수용량 <= 원소의 크기
		{
			capacity = capacity * 2;	// 최대 수용량
			ResizeVector(capacity);		// 기존 배열 -> 새로 만든 배열을 옮기는 작업
		}
		vec[size] = data;	// vec[0] = vec[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;		// 현재 객수가 0보다 크면 size - 1, 0보다 작거나 같으면 size = 0;
	}

	void Print()
	{
		std::cout << "-----------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "번째 값 출력 : " << vec[i] << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
	// private에 있는 vec에 직접접근
	T* GetVec() { return vec; }
	// 현재 vec의 원소 갯수를 리턴하는 함수
	int GetSize() { return size; }	


	// 로비 시스템, Rome - Player, Add, Remove 유저가 방에 들어갔다 나왔다
	// Player.Inventory - item system
};