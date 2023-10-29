#pragma once
#include <iostream>
#include <list>

using namespace std;
class GraphLib
{
	int numOfVertices;
	list<int>* adjLists;
	//list<bool>* visited;


public:
	GraphLib(int vertices);
	~GraphLib();
	void InsertEdge(int v, int e);
	void InsertVertexAt(int data, int position, int vertex);
	void InsertVertexAtRandom();
	list<int> GetAdjacentNodes(int vertex) const;
	list<int> GetVertices();
	list<pair<int, int>> GetAllEdges() const;
	int GetNodeData(int vertex) const;
	void PrintGraph();
	void DeleteEdge(int v, int e);
	void DFS(int startvertex);
	void DFSRecursiveFunc(int vertex, list<int>& visited);
	int Size() const;
	bool isEmpty() const;
	
};


