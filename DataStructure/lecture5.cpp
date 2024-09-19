#include"lectures.h"
#include"MyVector.h"
#include"RandomNumber.h"

// ���� �迭(Vector) - Array List

// ����(Vector)
// ���� ����ϴ� �ڷᱸ���� �ϳ�. Linked List, Array List(Vector)
// �迭�� Ư¡�� ��� ���´�
// arr[10];
// ������ �����ε����� ���� [], ==, !=


// ���Ḯ��Ʈ  vs  ���� �迭

//						  |	�ڷᱸ�� ũ�� ���� ��� | �߰�����, ���� ��� | �������� ��� | �������� ��� |
// ���Ḯ��Ʈ(LinkedList)  |          o			  |          o         |       o      |      x       |
// ���� �迭(Vector)		  |			 o			  |          X         |       o      |      o       |
// �÷��̾��� �κ��丮 -> LinkedList Inventory, Vector Inventory

// ���� : ũ�� �߰� ���� ��ɰ� ���� ���� ������� �� �ڷᱸ���� �������� ���� �� �ִ�
// �߰�����, ������ ���ų� ���� �߻��ϴ� ��쿡�� Vector�� ����ϸ� ����
// �߰�����, ������ ���� �߻��ϴ� ��쿡�� ���� ����Ʈ�� ����ϸ� ����

void lecture5()
{
	MyVector<float> i_Vec(20);
	MyVector<float> i_Vec2;

	if (i_Vec != i_Vec2)
	{
		std::cout << "������ �����ε��� ���������� ����� �˴ϴ�" << std::endl;
	}

	i_Vec.push_back(0.1f);
	i_Vec.push_back(0.2f);
	i_Vec.push_back(0.3f);
	i_Vec.Print();

	int r_index = R_Number(0, i_Vec.GetSize() - 1);
	std::cout << "i_Vec ���� ���ҿ� ����  : " << r_index + 1 << std::endl;
	std::cout << "���� �� : " << i_Vec[r_index] << std::endl;
	
	std::cout << "i_Vec 0��° ���ҿ� ���� " << i_Vec[0] << std::endl;
	std::cout << "private ����� vec�� ���� ���� " << i_Vec.GetVec()[0] << std::endl;
	
	i_Vec.pop_back();
	i_Vec.Print();

	// Vector Ư¡ : ������ ���ҿ� �����ϴ� �ð��� O(1);
	// Vector ���� ���ҿ� �����ϴ� ��� ����
	// int randomNumber = <<	C : srand(time(nullptr)); rand() % 100 + 1; ���� seed 

}