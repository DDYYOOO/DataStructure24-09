#pragma once
#include<iostream>
#include<set> 

// Set 자료구조 특징
// Red-Black Tree로 구현 되어있다.
// 정렬되어있는 자료구조
// 중복을 허용하지 않는다.

// 다음 순서를 레드 블랙 트리에 맞게 표현
// 8-7-9-3-6-4-5-12-10-11
// Node
//{
//	enum Color{RED, BLACK};
//}

// balanced BST 사용되고 있는 set
// 탐색, 삽입, 삭제 => log n
// data 사이의 크기 비교를 해야하는데, 어떻게 할 것인가? -> 프로그래머가 직접 설계
// string char* 
// apple banana

template<typename T1, typename T2>
struct MyPair
{
	T1 first;	// key
	T2 second;	// value

	MyPair() : first(), second() {}
	MyPair(const T1& x, const T2& y) : first(x), second(y) {}

	const T1& GetFirst() { return first; }
	const T2& GetSecond() { return second; }
};

class SomeData
{
private:
	int count;
	float time;
public:
	SomeData(int _count, float _time) : count(_count), time(_time) {}

	void Print()
	{
		std::cout << count << ", " << time << std::endl;
	}
};


void SetExample()
{
	std::set<int> mySet;

	mySet.emplace(1);
	mySet.emplace(10);
	mySet.emplace(1000);
	mySet.emplace(15);
	mySet.emplace(20);
	mySet.emplace(-1000);
	mySet.emplace(25);

	for (const int num : mySet)
	{
		std::cout << num << " ";
	}

	std::set<SomeData*> set2;

	set2.insert(new SomeData(1, 0.5f));
	set2.insert(new SomeData(2, 1.5f));
	set2.insert(new SomeData(4, 0.8f));

	std::cout << "pair 예제 " << std::endl;

	MyPair<int, SomeData*> mp1(1, new SomeData(1, 0.5f));
	MyPair<int, SomeData*> mp2(2, new SomeData(2, 1.5f));
	MyPair<int, SomeData*> mp4(4, new SomeData(4, 0.8f));

	std::cout << "NO" << mp1.GetFirst() << std::endl;
	mp1.GetSecond()->Print();
	
	std::cout << "멀티 셋 예제" << std::endl;

	std::multiset<int> mymultiSet;

	mymultiSet.emplace(1);
	mymultiSet.emplace(10);
	mymultiSet.emplace(1000);
	mymultiSet.emplace(15);
	mymultiSet.emplace(20);
	mymultiSet.emplace(-1000);
	mymultiSet.emplace(25);
	mymultiSet.emplace(10);
	mymultiSet.emplace(5);
	mymultiSet.emplace(15);
	mymultiSet.emplace(1000);

	for (const int num : mymultiSet)
	{
		std::cout << num << " ";
	}

}

