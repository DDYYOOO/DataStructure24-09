#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>	// swap함수 내장

// 자료구조를 이용해서 데이터를 잘 저장하는 방법을 배웠다
// 자료구조들 안에 있는 데이터를 가장 빠르고, 효율적으로 사용하는 방법을 배워야 한다 -> 알고리즘

// Heap
// 특징 : 완전 이진트리의 형태를 갖고 있다 
// 1. 가장 위의 데이터(노드)를 root라고 부르고, root 1개만 존재
// 2. 각 노드들은 자식을 2개까지 가질 수 있다
// 3. 노드들의 level이 가득찰 때까지 자식을 추가한다
// 4. 노드들의 자식들을 왼쪽부터 차례대로 채우는 형식 - 완전 이진트리
// 종류 
// Max Heap : 우선순위가 높은 데이터(큰 수) 가장 큰 수가 위로 올라가는 형태
// Min Heap : 가장 작은 수가 root 노드에 존재하는 heap구조

// Heapify의 규칙
// root의 노드를 pop한다
// 가장 마지막에 들어온 노드를 root에 넣어준다
// root의 자식들과 부모랑 비교를 해서 큰 수를 부모와 바꾼다
// 최초에 root들어간 녀식이 더 이상 변경되지 않을 때까지 반복

// 부모노드 구하는 공식 : (idx - 1) / 2
// 부모노드 기준 자식노드 왼쪽 : (idx * 2) + 1
// 부모노드 기준 자식노드 오른쪽 : (idx * 2) + 2

class PriorityQueue
{
private:
	std::vector<int> p_queue;
	
	// 부모노드 < idx노드(새로 들어온 노드) -> 새로 들어온 노드swap = false
	void heapifyUp(int idx)	// 마지막에 들어온 idx
	{
		//int a1 = 10;
		//int a2 = 20;
		//std::swap(a1, a2);
	}

	// 마지막 원소 : size - 1 -> root
	// left, right
	// int largest
	// while, 비교
	void heapifyDown(int idx) // 0
	{

	}

public:

};