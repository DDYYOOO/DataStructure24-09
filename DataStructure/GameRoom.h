#pragma once
#include<iostream>
#include<string>
#include<vector>
// Room - User System <= 자료구조를 사용해서 클래스를 만들겠다
// 1. List<사용자 정의형 클래스> iList; <<- 자료구조에 새로운 클래스 타입을 저장한다
// 2. class GameRoom{ private : vector m_myVector;}

// 방에 들어온 유저의 정보(확장성) 
// (private) 필드 : name : std::string, id : int, level : int
// (public) 기능  : getName(), getId(), getLevel(), getUserInfo()

// GameRoom 유저를 저장하는 클래스 
// UserInfo - 배열, 가변형 배열, 연결 리스트 저장
// addPlayer, deletePlayer, showPlayerList, banPlayer(추가 정보), isEmpty, isFull


class UserInfo
{
private:
	std::string name;
	int id;
	int level;
public:
	UserInfo() {}
	UserInfo(std::string _name, int _id, int _level) : name(_name), id(_id), level(_level) {}
	void GetName()
	{
		std::cout << "유저 이름 : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "유저 아이디 : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "유저 레벨 : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

// 연결형 리스트 vs 가변 배열 
// GameRoom - User.
// 중간 삽입 삭제 - UserInfo
// 랜덤 접근

class GameRoom
{
// 배열로 UserInfo를 표현했을 때 문제점
// 확장성 -> 적합하지 않다
// 쓰는 경우 -> 절대 변하지 않을 확신
private:
	std::vector<UserInfo> users;
	int maxCount;		// 방 최대 인원 수
	int userCount;		// 현재 방 인원수
public:
	GameRoom(int max = 8) 
	{
		maxCount = max;
		userCount = 0;
	}

	void AddPlayer(UserInfo& user)
	{
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "방이 가득찼습니다" << std::endl;
		}
	}
	void BanPlayer(int order)	// 0 ~ 7 순서.... order 2 -> 3번째 users[2] 삭제
	{
		if (0 <= order <= users.size())
		{
			users[order].GetName();
			std::cout << "을 추방했습니다." << std::endl;

			users.erase(users.begin() + order);
			//std::vector<UserInfo>::Const_iterator Where;
			userCount--;
		}
		else
		{
			std::cout << "index가 유효하지 않습니다" << std::endl;
		}
	}
	void ShowListPlayer()
	{
		if (IsEmpty())
		{
			std::cout << "방에 사람이 없습니다" << std::endl;
			return;
		}

		// 시작부터 ~ 마지막까지
		for (int i = 0; i < userCount; i++)
		{
			users[i].ShowUserInfo();
		}
	}


	bool IsEmpty()
	{
		return userCount <= 0 ? true : false;
	}
	bool IsFull()
	{
		return userCount >= maxCount ? true : false;
	}

	void IsClear() // 방이 없어지는 함수
	{
		while (!IsEmpty())
		{
			users.pop_back();	// 끝에서부터 하나씩 지워준다
			userCount--;
		}
	}
	void IsClear2()
	{
		users.erase(users.begin(), users.end());
		userCount = 0;
	}
};


void IGameRoomExample()
{
	// 가상의 유저 3명을 생성
	UserInfo user1("A", 1000, 10);
	//user1.ShowUserInfo();
	UserInfo user2("B", 1001, 10);
	//user2.ShowUserInfo();
	UserInfo user3("C", 1002, 10);
	//user3.ShowUserInfo();

	GameRoom room1(3);
	room1.AddPlayer(user1);
	room1.AddPlayer(user2);
	room1.AddPlayer(user3);
	room1.BanPlayer(1);
	room1.ShowListPlayer();

	room1.IsClear();
	room1.ShowListPlayer();

}
