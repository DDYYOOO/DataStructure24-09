#pragma once
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>

/*
  balanced BST - �����͵��� ���ĵǾ� �־�� �Ѵ�
  ������ �Ǿ� ���� �ʾƵ� ������ �����͸� �˻��� �� �ִ� �ڷᱸ�� -> unordered_set, unordered_map (hashfunction)
  hashfunction : Ư�� �԰����� ������ ���� ��ȯ�ϴ� �Լ�
  hashKey : �ſ� ū ���ڸ� ������
  bucket : ���� ���ڷ� ��ȯ�� �Ѵ�
*/




void HashExample()
{
	std::unordered_set<std::string> unordSet;

	unordSet.reserve(5000);		// �̸� �޸� ���� Ȯ��

	unordSet.emplace("abc");
	unordSet.emplace("def");
	unordSet.emplace("hgc");

	unordSet.emplace("abc2");
	unordSet.emplace("def2");
	unordSet.emplace("hgc2");

	unordSet.emplace("abc3");
	unordSet.emplace("def3");
	unordSet.emplace("hgc3");

	for (const std::string& str : unordSet)
	{
		std::cout << str << std::endl;
	}
	
	std::cout << "abc : " << std::hash<std::string>{}("abc") << std::endl;

	// bucket �ٱ��� ����
	std::cout << "bucket �� : " << unordSet.bucket_count() << std::endl;

	unordSet.find("abc");

	// Ž���� ���� �ſ� ������, �����Ϳ� ����� ���� ������ �߰�, ���� �� ������ �ٲ��.



}
