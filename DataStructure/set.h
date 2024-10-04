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
}

