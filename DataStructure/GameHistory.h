#pragma once
#include<iostream>
#include<stack>
#include<string>
// Game���� �ֱ� �α׾ƿ��� �ð��� ����ϴ� Ŭ������ ���� ����

// GameData
// std::string iData; "2024-09-23/ 16:57:00"
// Print() {���ӷα׾ƿ��ð� : << iData;}

//class GameHistory
//Stack<GameData>
// pop, push
// SaveLogoutTime(std::string �ð�) <- push
// PrintLogoutTime() <- pop

class GameData
{
private:
	std::string iDate;

public:
	GameData(std::string _date) : iDate(_date) {}
	
	std::string GetDate() { return iDate; }

	void Print()
	{
		std::cout << "�α׾ƿ��� �ð� : " << iDate << std::endl;
	}
};

class GameHistory
{
private:
	std::stack<GameData> GameDatas;
	GameData* m_Data;
	int capacity;
	int top;
public:
	GameHistory() {}

	void SaveLogoutTime(GameData time)
	{
		GameDatas.push(time);
	}

	void PrintLogoutTime()
	{
		GameData printData = GameDatas.top();
		printData.Print();
		GameDatas.pop();
	}
};


void iGameHistoryExample()
{
	GameData data1("2024-09-20/17:00");
	GameData data2("2024-09-21/17:00");
	GameData data3("2024-09-22/17:00");
	GameData data4("2024-09-23/17:00");
	
	// Ư�� ������ �α׾ƿ��� �ð��� ����� �� �ִ� ���

	GameHistory GameDatas;

	GameDatas.SaveLogoutTime(data1);
	GameDatas.SaveLogoutTime(data2);
	GameDatas.SaveLogoutTime(data3);
	GameDatas.SaveLogoutTime(data4);
	
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();


}
