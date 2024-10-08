#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<set>

// �׷��� :  Vertex(��)�� edge(��)���� ������ ���� ���� ���踦 ���������� ǥ���� �ڷᱸ��

// �׷��� Ư��(feature)
// 1. ���⼺�� ���ų�, ���� �ʴ´� (directed vs undirected)
// 2. ���� ����ġ�� ���°�? weighted, ����� ���� ����ġ�� �ο��� �� �ִ�. �ο����� ������ 0, 1�� ǥ��
// 3. ��ȸ�ϴ°�?	cyclic Graph vs Acyclic Graph

// Graph Therory �׷��� �̷�
// DAG(Directed Acyclic Graph) : Ʈ���� �� ����

// �׷����� ǥ��
// 1. adjacent Matrix ���� ��Ʈ����
// 2. adjacent List ���� ����Ʈ

class Graph_Matrix
{
private:
	int vertex;		// ������ ��
	std::vector<std::vector<int>> adjMatrix;	// �׷������� ���� ���� ���� ǥ��

public:
	Graph_Matrix(int vertices) : vertex(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0))
	{

	}

	void AddEdge(int v1, int v2)
	{
		adjMatrix[v1][v2] = 1;
		adjMatrix[v2][v1] = 1;
	}

	void PrintGraph()
	{
		for (int i = 0; i < vertex; i++)
		{
			for (int j = 0; j < vertex; j++)
			{
				std::cout << adjMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

class Graph_List
{
private:
	int vertex;								// ������ ��
	std::vector<std::vector<int>> adjList;	// �׷������� ���� ���� ���� ǥ��

public:
	Graph_List(int vertices) : vertex(vertices) 
	{
		adjList.resize(vertices);
	}

	void AddEdge(int v1, int v2)
	{
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	void PrintGraph()
	{
		for (int i = 0; i < vertex; i++)
		{
			std::cout << "���� " << i << "�� ���� ��Ʈ���� : ";
			for (auto x : adjList[i])
			{
				std::cout << "->" << x;
			}
			std::cout << std::endl;
		}
	}
};

// �׷��� Ž�� ����
// 0�� ������ 1, 3 ����
// 1�� ������ 0, 1, 3, 5����
// 2�� ������ 2, 4����
// 3�� ������ 0, 2����
// 4, 5�� ������ ���� �ȵ�

// �� ���� ��ü�� ����Ǿ� ������ true��ȯ, �ƴϸ� false��ȯ�ϵ��� �ڵ� �ۼ�

class Visit_Room
{
private:
	std::vector<std::vector<int>> rooms;	// ����� �׷����� ǥ���ϴ� 2���� �迭
	std::set<int> seen;						// Ž���� ���� �����ϴ� �ڷᱸ��

	// ��� ���
	void RecurDFS(std::vector<std::vector<int>>& rooms)
	{
		// stack : ������ vertex ����, seen �ְ�, ���


	}

	// iterative
	void IterDFS()
	{
		while (1)
		{

		}
	}

	void BFS()
	{

	}

public:
	Visit_Room() {}
};

void GraphExample()
{
	std::cout << "Graph List" << std::endl;

	Graph_List graph_L(5);
	
	graph_L.AddEdge(0, 2);
	graph_L.AddEdge(0, 3);
	graph_L.AddEdge(1, 3);
	graph_L.AddEdge(1, 4);
	graph_L.AddEdge(2, 4);
	
	graph_L.PrintGraph();

	std::cout << "Graph Matrix" << std::endl;

	Graph_Matrix graph_M(5);
	
	graph_M.AddEdge(0, 2);
	graph_M.AddEdge(0, 3);
	graph_M.AddEdge(1, 3);
	graph_M.AddEdge(1, 4);
	graph_M.AddEdge(2, 4);
	
	graph_M.PrintGraph();

}
