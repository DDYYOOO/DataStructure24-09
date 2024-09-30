#pragma once
#include<iostream>
#include<queue>
#include<string>
// 플레이어의 커맨드를 출력하는 기능 구현
// 
// class의 상속 관계 command 상속해서 구현
// draw.io 다이어그램 구상
// 
// std::in << input;
// std::<queue> inputs; 
// std::<queue> temp;
// temp.front() ... pop()
// [				]

class Command
{
protected:
	std::string key;		// 키 : Command 명령어를 저장
public:
	Command(std::string _key) : key(_key) {}	// 커맨드 클래스의 생성자 - 키를 초기화
	virtual ~Command() = default;				// 부모 클래스가 가장 마지막에 소멸되도록 해주는 코드
	virtual std::string Execute() const = 0;	// 모든 커맨드의 실행 가능
	std::string GetKey() { return key; }
};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string Execute() const override
	{
		return "FireBall 시전";
	}
};

class IceArrow : public Command
{
public:
	IceArrow(std::string key) : Command(key) {}
	std::string Execute() const override
	{
		return "IceArrow 시전";
	}
};

template<typename T>
class CircularQueue2
{
private:
	T* arr;			// T 타입의 배열 이름
	int iCount;		// 현재 원소의 수
	int iMaxCount;	// 최대 저장 가능한 수
	int front;		// front index
	int rear;		// rear index
public:
	// 생성자
	CircularQueue2(int size = 4)
	{
		iMaxCount = size;
		arr = new T[size];
		iCount = 0;
		front = 0;
		rear = 0;
	}

	// 접근자(Accessor)
	T Front() { return arr[front]; }
	T Rear() { return arr[rear]; }
	int size() { return iCount; }

	// Helper Method
	bool IsEmpty()
	{
		return rear == front ? true : false;
	}
	bool IsFull()
	{
		return (rear + 1) % iMaxCount == front ? true : false;
	}

	// Main Method
	void Push(T data)
	{
		if (IsFull())
		{
			std::cout << "원형 큐가 가득찼습니다" << std::endl;
		}
		else
		{
			arr[rear] = data;
			rear = (rear + 1) % iMaxCount;
			iCount++;
		}
	}
	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "원형 큐가 비었습니다" << std::endl;
			return;
		}
		else
		{
			front = (front + 1) % iMaxCount;
			iCount--;
		}
	}

};

/// <summary>
/// Command를 사용해서 특별할 동작을 실행하는 클래스
/// </summary>
class CommandSystem
{
private:
	std::vector<Command*>  Commands;	//  특별한 이유가 없으면 vector가 효율적(원소수가 적을수록 유리)
	CircularQueue2<std::string> inputs;		// 유저가 보낸 신호를 순서대로 저장을 해야 하는 데이터

public:
	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}

	void addInuput(const std::string input)
	{
		// 최대 갯수
		if (inputs.size() < 3)
		{
			// 예외처리구현은 안되어 있다
			inputs.Push(input);
		}

		if (inputs.size() == 3)
		{
			ProcessCommand();	// 커맨드 실행
			ClearQueue();		// 큐를 비워줌
		}
	}

	void ProcessCommand()
	{
		std::string userCommand = "";	// 유저가 입력한 순서대로 커맨드가 실행

		while (!inputs.IsEmpty())		// 큐가 0이 될때까지 실행
		{
			userCommand += inputs.Front();
			inputs.Pop();
		}

		for (int i = 0; i < Commands.size(); i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->Execute() << std::endl;
				return;
			}
		}

		std::cout << "일치하는 커맨드가 없습니다." << std::endl;

	}

	void ClearQueue()
	{
		while (!inputs.IsEmpty())
		{
			inputs.Pop();
		}
	}

	void ShowCommandList()
	{
		std::cout << "커맨드 목록" << std::endl;
		std::cout << "FireBall 커맨드 : " << "ABC" << std::endl;
		std::cout << "IceArrow 커맨드 : " << "DEF" << std::endl;
		std::cout << "===========================" << std::endl;
	}

	void ShowPlayerInputs()
	{
		std::cout << "현재 입력 값 : [";
		CircularQueue2<std::string> temp = inputs;

		while (!temp.IsEmpty())		// 큐가 0이 될때까지 실행
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		
		std::cout << "]" << std::endl;
	}
};

// CommandSystem 호출 함수
void CommandSystemExample()
{
	CommandSystem manager;

	FireBall command1("ABC");
	IceArrow command2("DEF");

	manager.addCommand(&command1);
	manager.addCommand(&command2);

	std::string input;
	
	while (1)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInputs();

		std::cin >> input;
		manager.addInuput(input);

		if (input == "Q")
		{
			std::cout << "시스템 종료" << std::endl;
			break;
		}
	}
}