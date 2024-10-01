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
	std::vector<int> heap;
	
	// �θ��� < idx���(���� ���� ���) -> ���� ���� ���swap = false
	void heapifyUp(int idx)	// �������� ���� idx
	{
		// �� :  ���� ���� ���, �� ����� �θ���
		while (heap[idx] > heap[(idx - 1) / 2])	// ���� ���� ��尡 �θ� ��庸�� �۴ٸ� break;
		{
			std::swap(heap[idx], heap[(idx - 1) / 2]);
			idx = (idx - 1) / 2;
		}
	}

	// ������ ���� : size - 1 -> root
	// left, right
	// int largest
	// while, ��
	void heapifyDown(int idx) // 0
	{
		int size = heap.size();

		while (1)
		{
			int largest = idx;
			int left = (idx * 2) + 1;
			int right = (idx * 2) + 2;

			if (left < size && heap[largest] < heap[left])
				largest = left;

			if (right < size && heap[largest] < heap[right])
				largest = right;

			if (largest == idx)
				break;

			std::swap(heap[largest], heap[idx]);
			idx = largest;
		}


	}

public:
	void Push(int _data)
	{
		heap.push_back(_data);
		heapifyUp(heap.size() - 1);
	}
	int Pop()
	{
		// ����ó��
		if (heap.empty())
		{
			throw std::out_of_range("���� ������ϴ�");
		}

		int root = heap[0];				// 1. ���� ū ���� root�� ����
		heap[0] = heap.back();			// 3. ����ִ� root�� ���� ������ ���Ҹ� ���� 
		heap.pop_back();				// 4. ���� ������ �������� ������ ����� pop_back
		heapifyDown(0);					// 5. ���� Ư���� �°� ������

		return root;					// 2. ���� ��Ų��.(�ִ� ���)
	}

	int top() const
	{
		if (heap.empty())
		{
			throw std::out_of_range("���� ������ϴ�");
		}

		return heap[0];
	}
	
	bool empty() const { return heap.empty(); }
	int size() const { return heap.size(); }

};


void PriorityQueueExample()
{
	PriorityQueue p_q;
	p_q.Push(1);
	p_q.Push(3);
	p_q.Push(5);
	p_q.Push(7);
	p_q.Push(9);

	while (!p_q.empty())
	{
		std::cout << "�켱���� ť ��� : " << p_q.Pop() << std::endl;
	}
}