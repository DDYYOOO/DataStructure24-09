#pragma once
#include<iostream>
#include<string>
#include<vector>
// Room - User System <= �ڷᱸ���� ����ؼ� Ŭ������ ����ڴ�
// 1. List<����� ������ Ŭ����> iList; <<- �ڷᱸ���� ���ο� Ŭ���� Ÿ���� �����Ѵ�
// 2. class GameRoom{ private : vector m_myVector;}

// �濡 ���� ������ ����(Ȯ�强) 
// (private) �ʵ� : name : std::string, id : int, level : int
// (public) ���  : getName(), getId(), getLevel(), getUserInfo()

// GameRoom ������ �����ϴ� Ŭ���� 
// UserInfo - �迭, ������ �迭, ���� ����Ʈ ����
// addPlayer, deletePlayer, showPlayerList, banPlayer(�߰� ����), isEmpty, isFull


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
		std::cout << "���� �̸� : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "���� ���̵� : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "���� ���� : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

// ������ ����Ʈ vs ���� �迭 
// GameRoom - User.
// �߰� ���� ���� - UserInfo
// ���� ����

class GameRoom
{
// �迭�� UserInfo�� ǥ������ �� ������
// Ȯ�强 -> �������� �ʴ�
// ���� ��� -> ���� ������ ���� Ȯ��
private:
	std::vector<UserInfo> users;
	int maxCount;		// �� �ִ� �ο� ��
	int userCount;		// ���� �� �ο���
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
			std::cout << "���� ����á���ϴ�" << std::endl;
		}
	}
	void BanPlayer(int order)	// 0 ~ 7 ����.... order 2 -> 3��° users[2] ����
	{
		if (0 <= order <= users.size())
		{
			users[order].GetName();
			std::cout << "�� �߹��߽��ϴ�." << std::endl;

			users.erase(users.begin() + order);
			//std::vector<UserInfo>::Const_iterator Where;
			userCount--;
		}
		else
		{
			std::cout << "index�� ��ȿ���� �ʽ��ϴ�" << std::endl;
		}
	}
	void ShowListPlayer()
	{
		if (IsEmpty())
		{
			std::cout << "�濡 ����� �����ϴ�" << std::endl;
			return;
		}

		// ���ۺ��� ~ ����������
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

	void IsClear() // ���� �������� �Լ�
	{
		while (!IsEmpty())
		{
			users.pop_back();	// ���������� �ϳ��� �����ش�
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
	// ������ ���� 3���� ����
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
