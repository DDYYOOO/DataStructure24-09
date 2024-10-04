#pragma once
#include<iostream>
#include<set> 

// Set �ڷᱸ�� Ư¡
// Red-Black Tree�� ���� �Ǿ��ִ�.
// ���ĵǾ��ִ� �ڷᱸ��
// �ߺ��� ������� �ʴ´�.

// ���� ������ ���� �� Ʈ���� �°� ǥ��
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

