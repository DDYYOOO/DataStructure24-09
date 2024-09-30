#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>	// swap�Լ� ����

// �ڷᱸ���� �̿��ؼ� �����͸� �� �����ϴ� ����� �����
// �ڷᱸ���� �ȿ� �ִ� �����͸� ���� ������, ȿ�������� ����ϴ� ����� ����� �Ѵ� -> �˰���

// Heap
// Ư¡ : ���� ����Ʈ���� ���¸� ���� �ִ� 
// 1. ���� ���� ������(���)�� root��� �θ���, root 1���� ����
// 2. �� ������ �ڽ��� 2������ ���� �� �ִ�
// 3. ������ level�� ������ ������ �ڽ��� �߰��Ѵ�
// 4. ������ �ڽĵ��� ���ʺ��� ���ʴ�� ä��� ���� - ���� ����Ʈ��
// ���� 
// Max Heap : �켱������ ���� ������(ū ��) ���� ū ���� ���� �ö󰡴� ����
// Min Heap : ���� ���� ���� root ��忡 �����ϴ� heap����

// Heapify�� ��Ģ
// root�� ��带 pop�Ѵ�
// ���� �������� ���� ��带 root�� �־��ش�
// root�� �ڽĵ�� �θ�� �񱳸� �ؼ� ū ���� �θ�� �ٲ۴�
// ���ʿ� root�� ����� �� �̻� ������� ���� ������ �ݺ�

// �θ��� ���ϴ� ���� : (idx - 1) / 2
// �θ��� ���� �ڽĳ�� ���� : (idx * 2) + 1
// �θ��� ���� �ڽĳ�� ������ : (idx * 2) + 2

class PriorityQueue
{
private:
	std::vector<int> p_queue;
	
	// �θ��� < idx���(���� ���� ���) -> ���� ���� ���swap = false
	void heapifyUp(int idx)	// �������� ���� idx
	{
		//int a1 = 10;
		//int a2 = 20;
		//std::swap(a1, a2);
	}

	// ������ ���� : size - 1 -> root
	// left, right
	// int largest
	// while, ��
	void heapifyDown(int idx) // 0
	{

	}

public:

};