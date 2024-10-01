#include "lectures.h"
#include<vector>
#include<chrono>

// 자료구조 안에 있는 데이터를 찾아서, 사용하기
// 데이터를 가장 효율적으로 저장하는 방법을 배움

// ADT, Queue, Stack, Priority_Queue

// 자료구조 내부에 있는 데이터를 어떻게 빠르게 찾을 수 있는가
// 1순위 시간 복잡도(Time Complexity)
// 2순위 공간 복잡도(Space Complexity)

// for 반복문을 통해서 모든 원소를 순회(traverse) 시간 O(n) : 데이터가 많을수록 오래걸린다.
// O(logn) - 자료구조가 정렬되어있으면, 이진 탐색(binary search)으로 O(logn)탐색 할 수 있다. 
// O(1)

// 자료구조의 vector 이진 탐색을 구현
// LinkedList -> 이진탐색이 불가능
// 중간에 데이터 삽입, 삭제 발생 vector_rebluiding

class MySeacrchTool
{
private:

public:
	int Search(const std::vector<int>& arr, int target)
	{
		auto it = arr.begin();

		// iterator 반복문
		for (it; it != arr.end(); it++)
		{
			if ((*it) == target)
			{
				std::cout << "목표값을 찾았습니다." << std::endl;
				return (*it);
			}
		}

		std::cout << "목표값을 찾지 못했습니다." << std::endl;
		return -1;
	}
	int BinarySearch(const std::vector<int>& arr, int target)
	{
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			// mid target 클 때
			if (arr[mid] > target)
			{
				left = mid + 1;
			}
			// mid target 작을 때
			else if (arr[mid] < target)
			{
				right = mid - 1;
			}
			// mid target 일 때
			else	//(arr[mid] == target)
			{
				std::cout << "목표값을 찾았습니다." << std::endl;
				return arr[mid];
			}

			// 배열 인덱스 mid, left, right
		}

		std::cout << "목표값을 찾지 못했습니다." << std::endl;
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

	// vec 안에 있는 숫자를 찾는다 <- 탐색
	int targetNumber = 3;
	
	MySeacrchTool tool;

	std::cout << "목표값 : " << targetNumber << std::endl;

	// Search() 걸린 시간
	auto start = std::chrono::high_resolution_clock::now();

	tool.Search(vec, targetNumber);

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "for 반복문 순회 탐색 방식 걸린 시간 : " << duration.count() / 1000.0 << "ms" << std::endl;

	//BinarySearch() 걸린 시간
	auto start2 = std::chrono::high_resolution_clock::now();

	tool.BinarySearch(vec, targetNumber);

	auto end2 = std::chrono::high_resolution_clock::now();

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

	std::cout << "이진 탐색 방식 걸린 시간 : " << duration2.count() / 1000.0 << "ms" << std::endl;


	//범위 기반 반복문(range base for loop)
	//for (int elem : vec)
	//{
	//	if (elem == targetNumber)
	//	{
	//		std::cout << "목표값을 찾았습니다 => " << elem << std::endl;
	//		break;
	//	}
	//}
}