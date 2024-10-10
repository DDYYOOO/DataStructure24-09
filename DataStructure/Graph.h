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
	std::set<int> seen;

	void recur_DFS(int index)	// 0�� �˻�
	{
		std::cout << index << " ";					// ���� ������ ���
		seen.insert(index);							// 0�� seen����

		std::vector<int>& keys = adjList[index];	// ���� vertex�� ���� vertex�� ã�´�. 1, 0���� ũ�� �ִ�

		for (int key : keys)
		{
			if (seen.find(key) == seen.end())		// seen�� ���� �����Ͷ�� ����, seen.key �˻�, ������ true ����
			{
				recur_DFS(key);
			}
		}
	}

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

	bool RecurDFS()		// Graph DFS ����ؼ� ��� ��ΰ� ����Ǿ� �ִ��� �ľ��ϴ� �Լ�
	{
		seen.clear();
		recur_DFS(0);

		// seen. adjList
		if(seen.size() == adjList.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;

		return seen.size() == adjList.size();
	}

	void IterDFS(int index)
	{
		seen.clear();

		std::stack<int> s;		// ������ vertex ���� -> ������ vertex�� ������ vertex ����
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.top();
			s.pop();

			if (seen.find(vertex) == seen.end())		// �ߺ� ����
			{
				std::cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); it++)
				{
					if(seen.find(*it) == seen.end())
						s.push(*it);
				}
			}
		}

		if (seen.size() == adjList.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;
	}

	void IterBFS(int index)
	{
		seen.clear();

		std::queue<int> s;		// ������ vertex ���� -> ������ vertex�� ������ vertex ����
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.front();
			s.pop();

			if (seen.find(vertex) == seen.end())		// �ߺ� ����
			{
				std::cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjList[vertex].begin(); it != adjList[vertex].end(); it++)
				{
					if (seen.find(*it) == seen.end())
						s.push(*it);
				}
			}
		}

		if (seen.size() == adjList.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;
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

	Graph_List graph_L(7);
	
	//graph_L.AddEdge(0, 2);
	//graph_L.AddEdge(0, 3);
	//graph_L.AddEdge(1, 3);
	//graph_L.AddEdge(1, 4);
	//graph_L.AddEdge(2, 4);

	graph_L.AddEdge(0, 1);
	graph_L.AddEdge(1, 4);
	graph_L.AddEdge(4, 6);
	graph_L.AddEdge(0, 2);
	graph_L.AddEdge(2, 4);
	graph_L.AddEdge(2, 5);
	graph_L.AddEdge(0, 3);
	
	graph_L.PrintGraph();
	graph_L.RecurDFS();
	graph_L.IterDFS(0);
	graph_L.IterBFS(0);

	std::cout << "Graph Matrix" << std::endl;

	Graph_Matrix graph_M(5);
	
	graph_M.AddEdge(0, 2);
	graph_M.AddEdge(0, 3);
	graph_M.AddEdge(1, 3);
	graph_M.AddEdge(1, 4);
	graph_M.AddEdge(2, 4);
	
	graph_M.PrintGraph();

	//std::vector<std::vector<int>> example
	//{
	//	{0, 1},
	//	{1, 4},
	//}

}
