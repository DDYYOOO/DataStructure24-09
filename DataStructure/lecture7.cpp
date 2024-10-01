#include "lectures.h"
#include<vector>
#include<chrono>

// �ڷᱸ�� �ȿ� �ִ� �����͸� ã�Ƽ�, ����ϱ�
// �����͸� ���� ȿ�������� �����ϴ� ����� ���

// ADT, Queue, Stack, Priority_Queue

// �ڷᱸ�� ���ο� �ִ� �����͸� ��� ������ ã�� �� �ִ°�
// 1���� �ð� ���⵵(Time Complexity)
// 2���� ���� ���⵵(Space Complexity)

// for �ݺ����� ���ؼ� ��� ���Ҹ� ��ȸ(traverse) �ð� O(n) : �����Ͱ� �������� �����ɸ���.
// O(logn) - �ڷᱸ���� ���ĵǾ�������, ���� Ž��(binary search)���� O(logn)Ž�� �� �� �ִ�. 
// O(1)

// �ڷᱸ���� vector ���� Ž���� ����
// LinkedList -> ����Ž���� �Ұ���
// �߰��� ������ ����, ���� �߻� vector_rebluiding

class MySeacrchTool
{
private:

public:
	int Search(const std::vector<int>& arr, int target)
	{
		auto it = arr.begin();

		// iterator �ݺ���
		for (it; it != arr.end(); it++)
		{
			if ((*it) == target)
			{
				std::cout << "��ǥ���� ã�ҽ��ϴ�." << std::endl;
				return (*it);
			}
		}

		std::cout << "��ǥ���� ã�� ���߽��ϴ�." << std::endl;
		return -1;
	}
	int BinarySearch(const std::vector<int>& arr, int target)
	{
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			// mid target Ŭ ��
			if (arr[mid] > target)
			{
				left = mid + 1;
			}
			// mid target ���� ��
			else if (arr[mid] < target)
			{
				right = mid - 1;
			}
			// mid target �� ��
			else	//(arr[mid] == target)
			{
				std::cout << "��ǥ���� ã�ҽ��ϴ�." << std::endl;
				return arr[mid];
			}

			// �迭 �ε��� mid, left, right
		}

		std::cout << "��ǥ���� ã�� ���߽��ϴ�." << std::endl;
		return -1;
	}
};


void lecture7()
{
	std::vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// vec �ȿ� �ִ� ���ڸ� ã�´� <- Ž��
	int targetNumber = 3;
	
	MySeacrchTool tool;

	std::cout << "��ǥ�� : " << targetNumber << std::endl;

	// Search() �ɸ� �ð�
	auto start = std::chrono::high_resolution_clock::now();

	tool.Search(vec, targetNumber);

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "for �ݺ��� ��ȸ Ž�� ��� �ɸ� �ð� : " << duration.count() / 1000.0 << "ms" << std::endl;

	//BinarySearch() �ɸ� �ð�
	auto start2 = std::chrono::high_resolution_clock::now();

	tool.BinarySearch(vec, targetNumber);

	auto end2 = std::chrono::high_resolution_clock::now();

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

	std::cout << "���� Ž�� ��� �ɸ� �ð� : " << duration2.count() / 1000.0 << "ms" << std::endl;


	//���� ��� �ݺ���(range base for loop)
	//for (int elem : vec)
	//{
	//	if (elem == targetNumber)
	//	{
	//		std::cout << "��ǥ���� ã�ҽ��ϴ� => " << elem << std::endl;
	//		break;
	//	}
	//}
}