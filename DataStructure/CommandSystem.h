#pragma once
#include<iostream>
#include<queue>
#include<string>
// �÷��̾��� Ŀ�ǵ带 ����ϴ� ��� ����
// 
// class�� ��� ���� command ����ؼ� ����
// draw.io ���̾�׷� ����
// 
// std::in << input;
// std::<queue> inputs; 
// std::<queue> temp;
// temp.front() ... pop()
// [				]

class Command
{
protected:
	std::string key;		// Ű : Command ��ɾ ����
public:
	Command(std::string _key) : key(_key) {}	// Ŀ�ǵ� Ŭ������ ������ - Ű�� �ʱ�ȭ
	virtual ~Command() = default;				// �θ� Ŭ������ ���� �������� �Ҹ�ǵ��� ���ִ� �ڵ�
	virtual std::string Execute() const = 0;	// ��� Ŀ�ǵ��� ���� ����
	std::string GetKey() { return key; }
};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string Execute() const override
	{
		return "FireBall ����";
	}
};

class IceArrow : public Command
{
public:
	IceArrow(std::string key) : Command(key) {}
	std::string Execute() const override
	{
		return "IceArrow ����";
	}
};

template<typename T>
class CircularQueue2
{
private:
	T* arr;			// T Ÿ���� �迭 �̸�
	int iCount;		// ���� ������ ��
	int iMaxCount;	// �ִ� ���� ������ ��
	int front;		// front index
	int rear;		// rear index
public:
	// ������
	CircularQueue2(int size = 4)
	{
		iMaxCount = size;
		arr = new T[size];
		iCount = 0;
		front = 0;
		rear = 0;
	}

	// ������(Accessor)
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
			std::cout << "���� ť�� ����á���ϴ�" << std::endl;
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
			std::cout << "���� ť�� ������ϴ�" << std::endl;
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
/// Command�� ����ؼ� Ư���� ������ �����ϴ� Ŭ����
/// </summary>
class CommandSystem
{
private:
	std::vector<Command*>  Commands;	//  Ư���� ������ ������ vector�� ȿ����(���Ҽ��� �������� ����)
	CircularQueue2<std::string> inputs;		// ������ ���� ��ȣ�� ������� ������ �ؾ� �ϴ� ������

public:
	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}

	void addInuput(const std::string input)
	{
		// �ִ� ����
		if (inputs.size() < 3)
		{
			// ����ó�������� �ȵǾ� �ִ�
			inputs.Push(input);
		}

		if (inputs.size() == 3)
		{
			ProcessCommand();	// Ŀ�ǵ� ����
			ClearQueue();		// ť�� �����
		}
	}

	void ProcessCommand()
	{
		std::string userCommand = "";	// ������ �Է��� ������� Ŀ�ǵ尡 ����

		while (!inputs.IsEmpty())		// ť�� 0�� �ɶ����� ����
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

		std::cout << "��ġ�ϴ� Ŀ�ǵ尡 �����ϴ�." << std::endl;

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
		std::cout << "Ŀ�ǵ� ���" << std::endl;
		std::cout << "FireBall Ŀ�ǵ� : " << "ABC" << std::endl;
		std::cout << "IceArrow Ŀ�ǵ� : " << "DEF" << std::endl;
		std::cout << "===========================" << std::endl;
	}

	void ShowPlayerInputs()
	{
		std::cout << "���� �Է� �� : [";
		CircularQueue2<std::string> temp = inputs;

		while (!temp.IsEmpty())		// ť�� 0�� �ɶ����� ����
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		
		std::cout << "]" << std::endl;
	}
};

// CommandSystem ȣ�� �Լ�
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
			std::cout << "�ý��� ����" << std::endl;
			break;
		}
	}
}