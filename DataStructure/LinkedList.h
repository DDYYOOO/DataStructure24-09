#pragma once
#include<iostream>
#include<string>
// 자료구조  : 데이터를 잘 사용하기 위해서 선택하는 도구
// 시간 복잡도(빅오 표기법 O(n)) : 연산속도가 적을수록 실행이 빠르다
// 공간 복잡도(빅오 표기법 O(n)) : 크기가 작을수록 메모리 공간이 많이 남는다.

// 알고리즘
// 1. 데이터 저장(Insert) <-> (삭제)
// 2. 1 ~ n번 출력(순회) <-> (역순회)
// 3. 데이터 정렬
// 4. 데이터 탐색

// 배열
// 장점 : 배열의 속해있는 원소의 접근이 짧다(arr[10] O(1))
// 단점 : 데이터 삭제 및 저장 : O(n) - 데이터의 크기가 크면 클수록 시간이 오래걸린다.

// 연결 리스트
// 장정 : 데이터 삭제 및 저장 : O(1) - 삭제 및 저장에 시간이 매우 빠르다
// 단점 : 임의의 원소에 접근하는 시간이 길다 O(n)

// Simple(단일) 연결 리스트 : 단일 + 연결 + 리스트 = 자료구조
// 추상 데이터 형식(ADT)
// 1. 데이터와 링크(포인터) 쌍으로 이루어져있는 노드를 원소마다 소유 => 노드라는 객체를 설명
// 2. 연결 리스트 객체는 첫번째 노드를 head라는 이름으로 갖고 마지막 노드를 tail라는 이름을 갖는다 => tList(head, tail)
// 3. 방향은 단일 방향이여야 한다.

// 정수를 저장하는 단일 연결 리스트

// 정수의 값을 저장하는 노드

struct IntNode
{
	int value;	    // 노드가 저장하고 있는 정수의 값
	IntNode* pNext; // 다음 노드의 주소를 저장하는 포인터
	IntNode* pPrev;
};

// 그 노드를 필드로 갖는 단일 연결 리스트라는 객체

class ILinkedList
{
private:
	IntNode* pHead;		// 노드의 첫번째를 저장
	IntNode* pTail;		// 노드의 마지막을 저장
	int iCount;		// 노드의 총 갯수
	
public:
	ILinkedList();	// 생성자
	~ILinkedList();	// 소멸자

	// Node추가
	void PushFront(const int& data);
	void PushBack(const int& data);

	// Node삭제
	void RemoveFront();
	void RemoveBack();

	// 데이터 보여주는 기능
	void FrontValue();
	void TailValue();
};

