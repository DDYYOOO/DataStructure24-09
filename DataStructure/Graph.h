#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<set>

// 그래프 :  Vertex(점)와 edge(선)으로 데이터 간의 연결 관계를 범용적으로 표현한 자료구조

// 그래프 특색(feature)
// 1. 방향성을 갖거나, 갖지 않는다 (directed vs undirected)
// 2. 선이 가중치를 갖는가? weighted, 연결된 선의 가중치를 부여할 수 있다. 부여하지 않으면 0, 1로 표현
// 3. 순회하는가?	cyclic Graph vs Acyclic Graph

// Graph Therory 그래프 이론
// DAG(Directed Acyclic Graph) : 트리의 한 종류

// 그래프의 표현
// 1. adjacent Matrix 인접 매트릭스
// 2. adjacent List 인접 리스트

class Graph_Matrix
{
private:
	int vertex;		// 정점의 수
	std::vector<std::vector<int>> adjMatrix;	// 그래프들의 연결 관계 정보 표현

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
	int vertex;								// 정점의 수
	std::vector<std::vector<int>> adjList;	// 그래프들의 연결 관계 정보 표현
	std::set<int> seen;

	void recur_DFS(int index)	// 0번 검색
	{
		std::cout << index << " ";					// 시작 데이터 출력
		seen.insert(index);							// 0번 seen삽입

		std::vector<int>& keys = adjList[index];	// 시작 vertex의 인접 vertex를 찾는다. 1, 0보다 크면 있다

		for (int key : keys)
		{
			if (seen.find(key) == seen.end())		// seen에 없는 데이터라면 실행, seen.key 검색, 없으면 true 실행
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

	bool RecurDFS()		// Graph DFS 사용해서 모든 경로가 연결되어 있는지 파악하는 함수
	{
		seen.clear();
		recur_DFS(0);

		// seen. adjList
		if(seen.size() == adjList.size())
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;

		return seen.size() == adjList.size();
	}

	void IterDFS(int index)
	{
		seen.clear();

		std::stack<int> s;		// 인접한 vertex 저장 -> 저장한 vertex의 인접한 vertex 저장
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.top();
			s.pop();

			if (seen.find(vertex) == seen.end())		// 중복 방지
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
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;
	}

	void IterBFS(int index)
	{
		seen.clear();

		std::queue<int> s;		// 인접한 vertex 저장 -> 저장한 vertex의 인접한 vertex 저장
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.front();
			s.pop();

			if (seen.find(vertex) == seen.end())		// 중복 방지
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
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;
	}

	void PrintGraph()
	{
		for (int i = 0; i < vertex; i++)
		{
			std::cout << "정점 " << i << "의 인접 매트릭스 : ";
			for (auto x : adjList[i])
			{
				std::cout << "->" << x;
			}
			std::cout << std::endl;
		}
	}
};

// 그래프 탐색 문제
// 0번 문에는 1, 3 연결
// 1번 문에는 0, 1, 3, 5연결
// 2번 문에는 2, 4연결
// 3번 문에는 0, 2연결
// 4, 5번 문에는 연결 안됨

// 이 문이 전체가 연결되어 있으면 true반환, 아니면 false반환하도록 코드 작성

class Visit_Room
{
private:
	std::vector<std::vector<int>> rooms;	// 방들을 그래프로 표현하는 2차원 배열
	std::set<int> seen;						// 탐색한 방을 저장하는 자료구조

	// 재귀 방식
	void RecurDFS(std::vector<std::vector<int>>& rooms)
	{
		// stack : 인접한 vertex 대입, seen 넣고, 출력


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
