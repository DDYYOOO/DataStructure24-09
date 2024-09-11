#include "Complexity.h"


void Print()
{

}

void lecture1()
{
	// 시간 복잡도의 단순 계산 1. 
	float s = 0.0f;					// 연산 1번
	
	for (int i = 0; i < 10; i++)	// (비교 1번, 덧셈 1번, 증감 연산1) x n(10)
	{
		s += 1;
	}								// 3n + 1번 연산

	std::cout << "0 ~ 10까지의 합 : " << s << std::endl;

	// n의 범위를 크게 확장 1 ~ 1억(3억 + 1연산)

	// 시간 복잡도의 단순 계산 1-2(1 ~ n 더하기 : n(n + 1)/2 )

	int sum = 0;
	int count = 100;

	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count;		// 시간 복잡도 : 5 O(1);

	// 시간 복잡도를 계산하기위한 방법 : 빅오 표기법
	// Best case - 빅 오메가
	// Worst case - 빅오 표기법
	// Average case - 빅 세타

	// 빅오 표기법의 특징 
	// 1. 가장 큰 차수 (n^3+n^2+n+1 n = 10억 10억 * 10억 * 10억 + 10억 * 10억 + 10억 + 1) : n의3제곱(n^3)만 표기 -> O(n^3)
	// 2. 자주 사용하는 빅오의 차이
	
	// (빠른 순서) O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n!)
	// a 숫자를 n번 곱해서 x를 구하라 a^n = x  n = alogax;
	// 특정 수를 n번 나눴을 때 언제 1이 되는지 구한다

}

void Example01()
{
	// 1. 시간 복잡도를 빠른 순서대로 빅오 표기로 출력
	// 출력 형태는 O(기호)를 갖추어서 O(a) < O(b) < ...... O(n!)

	// 2. 아래의 코드의 시간 복잡도와 공간 복잡도를 계산해서 std::cout출력
	// 시간 복잡도 : O()
	// 공간 복잡도 : O()

	int time = 61;
	int space = 3;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sum += sum + j;
		}
	}

	std::cout << "시간 복잡도 : O(" << time << ")" << std::endl;
	std::cout << "공간 복잡도 : O(" << space << ")" << std::endl;
}

// 공간 복잡도 예시
float abc(float a, float b, float c)
{
	return(a + b + b * c + (a + b - c) / (a + b) + 4.0);
	// 공간 복잡도 : 0(문제해결과 전혀 상관없는 메모리 공간)
}

float Sum(float a[], int n)
{
	float result = 0.0f;
	
	for (int i = 0; i <= n; i++)
	{
		result += a[i];
	}
	return result;
	// 공간 복잡도 : a[], n(1), result(1), i(1) => n + 3 => O(n)
}

