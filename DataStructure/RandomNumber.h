#pragma once

#include<iostream>
#include<cstdlib>	// rand() srand()
#include<ctime>		// time()
#include<random>	// C++ �����ϴ� �������̺귯��



int ReturnRandomNumber(int endNumber)	// s : 0 ~ e : 100 0���� 100���� ���ڸ� �����ϰ� ��ȯ�ϴ� �Լ�
{
	std::srand(time(nullptr));							// ���� �ð��� ����(seed)
	int randomNumber = std::rand() % endNumber + 1;		// 0 ~ endNumber - 1 ������ ������ ����
	return randomNumber;
}

int R_Number(int startNumber, int endNumber)
{
	std::random_device rd;		// seed�� �����ϱ� ���� ��ü
	std::mt19937 gen(rd());		// mt19937 �˰����� ����Ͽ� ������ ����
	std::uniform_int_distribution<> distrib(startNumber, endNumber);		// ���� ���ں��� �� ���ڱ��� ������ִ� ���
	int randomNumber = distrib(gen);
	return randomNumber;
}
