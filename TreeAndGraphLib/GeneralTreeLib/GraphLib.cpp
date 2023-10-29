#include "GraphLib.h"

using namespace std;
GraphLib::GraphLib(int vertices)
{
	this->numOfVertices = vertices;
	adjLists = new list<int>[vertices];
	std::srand(static_cast<unsigned>(std::time(0))); // random seed
}
GraphLib::~GraphLib() {
	
	//To prevent memeory leak
	for (int v = 0; v < numOfVertices; ++v) {
		adjLists[v].clear();
	}
	delete[] adjLists;
}
void GraphLib::InsertEdge(int v, int e)
{
	adjLists[v].push_back(e);
	adjLists[e].push_back(v);
	//adjLists[v].push_back(e); old code
}

list<int> GraphLib::GetAdjacentNodes(int vertex) const
{
	if (vertex >= 0 && vertex < numOfVertices) {
		return adjLists[vertex];

	}
	else {
		//error message
		return {};
	}
}
void GraphLib::InsertVertexAtRandom() {
	int randomPosition = std::rand() % (numOfVertices + 1);
	int newVertex = std::rand() % (numOfVertices + 1);
	int existingVertex1 = std::rand() % (numOfVertices + 1);
	int existingVertex2 = std::rand() % (numOfVertices + 1);

	InsertVertexAt(newVertex, existingVertex1, existingVertex2);
}

void GraphLib::InsertVertexAt(int vertex, int existingVertex1, int existingVertex2)
{
	InsertEdge(vertex, existingVertex1);
	InsertEdge(vertex, existingVertex2);


	

}

void GraphLib::PrintGraph()
{
	for (int v = 0; v < numOfVertices; ++v) {
		std::cout << "Adjacency list of vertex " << v << ": ";
		for (const auto& neighbor : adjLists[v]) {
			std::cout << neighbor << " ";
		}
		std::cout << std::endl;
	}
}

list<int> GraphLib::GetVertices()
{
	std::list<int> vertices;

	for (int v = 0; v < numOfVertices; ++v) {
		vertices.push_back(v);
	}

	return vertices;
}

list<pair<int, int>> GraphLib::GetAllEdges() const
{
	list<pair<int, int>> edges;

	for (int v = 0; v < numOfVertices; ++v) {
		for (const auto& neighbor : adjLists[v]) {
			
			if (v < neighbor) {
				edges.push_back({ v, neighbor });
			}
		}
	}

	return edges;
}

int GraphLib::GetNodeData(int vertex) const
{
	if (vertex >= 0 && vertex < numOfVertices) {
		
		return vertex;
	}
	else {
		
		return 0;  //error
	}
}


void GraphLib::DeleteEdge(int v, int e)
{
	auto it = std::find(adjLists[v].begin(), adjLists[v].end(), e);

	if (it != adjLists[v].end()) {
		adjLists[v].erase(it);
	}
}

void GraphLib::DFS(int startvertex)
{
	//get starting vertex then mark it as "visited"
	list<int> visited(numOfVertices, false);

	cout << startvertex << " ";
	DFSRecursiveFunc(startvertex, visited);
	cout << endl;

	/*list<int>::iterator it;
	for (it = adjLists[startvertex].begin(); it != adjLists[startvertex].end(); it++) {
		if (!visited[*it]) {
			DFS(*it);
		}

	}*/
}

void GraphLib::DFSRecursiveFunc(int vertex, list<int>& visited)
{

	visited.push_back(vertex);
	std::cout << vertex << " ";

	for (const auto& neighbor : adjLists[vertex]) {
		auto it = std::find(visited.begin(), visited.end(), neighbor);
		if (it == visited.end()) {
			DFSRecursiveFunc(neighbor, visited);
		}
	}
}

int GraphLib::Size() const
{
	return numOfVertices;
}

bool GraphLib::isEmpty() const
{
	return numOfVertices == 0;
}
//int main() {
//
//	GraphLib graph(8);
//	graph.InsertEdge(0, 1);
//	graph.InsertEdge(0, 2);
//	graph.InsertEdge(1, 3);
//	graph.InsertEdge(2, 3);
//	graph.InsertEdge(3, 4);
//	graph.InsertEdge(3, 5);
//	graph.InsertEdge(4, 6);
//	graph.InsertEdge(5, 6);
//	graph.DFS(1);
//	
//}


