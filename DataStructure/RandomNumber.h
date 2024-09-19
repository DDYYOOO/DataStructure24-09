#pragma once

#include<iostream>
#include<cstdlib>	// rand() srand()
#include<ctime>		// time()
#include<random>	// C++ 지원하는 랜덤라이브러리



int ReturnRandomNumber(int endNumber)	// s : 0 ~ e : 100 0부터 100까지 숫자를 랜덤하게 반환하는 함수
{
	std::srand(time(nullptr));							// 현재 시간을 난수(seed)
	int randomNumber = std::rand() % endNumber + 1;		// 0 ~ endNumber - 1 까지의 나머지 숫자
	return randomNumber;
}

int R_Number(int startNumber, int endNumber)
{
	std::random_device rd;		// seed를 생성하기 위한 객체
	std::mt19937 gen(rd());		// mt19937 알고리즘을 사용하여 난수를 생성
	std::uniform_int_distribution<> distrib(startNumber, endNumber);		// 시작 숫자부터 끝 숫자까지 출력해주는 기능
	int randomNumber = distrib(gen);
	return randomNumber;
}
