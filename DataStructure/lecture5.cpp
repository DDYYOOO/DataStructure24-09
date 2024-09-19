#include"lectures.h"
#include"MyVector.h"
#include"RandomNumber.h"

// 가변 배열(Vector) - Array List

// 벡터(Vector)
// 자주 사용하는 자료구조중 하나. Linked List, Array List(Vector)
// 배열의 특징을 모두 갖는다
// arr[10];
// 연산자 오버로딩으로 구현 [], ==, !=


// 연결리스트  vs  가변 배열

//						  |	자료구조 크기 변경 기능 | 중간삽입, 삭제 기능 | 순차접근 기능 | 랜덤접근 기능 |
// 연결리스트(LinkedList)  |          o			  |          o         |       o      |      x       |
// 가변 배열(Vector)		  |			 o			  |          X         |       o      |      o       |
// 플레이어의 인벤토리 -> LinkedList Inventory, Vector Inventory

// 정리 : 크게 중간 삽입 기능과 랜덤 접근 기능으로 두 자료구조의 차이점을 말할 수 있다
// 중간삽입, 삭제가 없거나 적게 발생하는 경우에는 Vector를 사용하면 좋다
// 중간삽입, 삭제가 자주 발생하는 경우에는 연결 리스트를 사용하면 좋다

void lecture5()
{
	MyVector<float> i_Vec(20);
	MyVector<float> i_Vec2;

	if (i_Vec != i_Vec2)
	{
		std::cout << "연산자 오버로딩이 정상적으로 출력이 됩니다" << std::endl;
	}

	i_Vec.push_back(0.1f);
	i_Vec.push_back(0.2f);
	i_Vec.push_back(0.3f);
	i_Vec.Print();

	int r_index = R_Number(0, i_Vec.GetSize() - 1);
	std::cout << "i_Vec 랜덤 원소에 접근  : " << r_index + 1 << std::endl;
	std::cout << "랜덤 값 : " << i_Vec[r_index] << std::endl;
	
	std::cout << "i_Vec 0번째 원소에 접근 " << i_Vec[0] << std::endl;
	std::cout << "private 선언된 vec에 직접 접근 " << i_Vec.GetVec()[0] << std::endl;
	
	i_Vec.pop_back();
	i_Vec.Print();

	// Vector 특징 : 임의의 원소에 접근하는 시간이 O(1);
	// Vector 랜덤 원소에 접근하는 기능 구현
	// int randomNumber = <<	C : srand(time(nullptr)); rand() % 100 + 1; 난수 seed 

}