#pragma once

#include<iostream>
#include<map>
#include<string>

// 학생 클래스

// 인데스 <- 정렬

class Student
{
private:
	std::string name;
	int score;
public:
	Student() {}
	Student(std::string _name, int _score) : name(_name), score(_score) {}

	std::string GetName() { return name; }
	int GetScore() { return score; }
};

class Player
{
private:
	std::string ID;
	int level;
public:
	Player() {}
	Player(std::string _ID, int _level) : ID(_ID), level(_level) {}
	
	std::string GetID() { return ID; }
	int GetLevel() { return level; }
};

void MapExample()
{
	//std::pair<int, Student*> myPair;

	std::map<int, Student*> myMap;

	// map에 데이터를 입력하는 방법

	myMap.emplace(std::make_pair(1, new Student("AAA", 100)));

	myMap.insert(std::make_pair(2, new Student("BBB", 200)));

	myMap.insert({ 4, new Student("CCC", 300) });

	myMap.insert(std::pair<int, Student*>(5, new Student("DDD", 400)));

	for (auto i = myMap.begin(); i != myMap.end(); i++)
	{
		std::cout << i->first << ", " << i->second->GetName() << ", " << i->second->GetScore() << std::endl;
	}

	std::map<int, Player*> player1;

	player1.emplace(std::make_pair(1, new Player("ABC", 5)));
	player1.emplace(std::make_pair(2, new Player("DEF", 10)));
	player1.emplace(std::make_pair(3, new Player("GHI", 15)));

	for (auto i = player1.begin(); i != player1.end(); i++)
	{
		std::cout << i->first << ", " << i->second->GetID() << ", " << i->second->GetLevel() << std::endl;
	}

}