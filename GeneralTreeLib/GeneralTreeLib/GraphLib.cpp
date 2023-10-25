#include "GraphLib.h"

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
		return {};
	}
}
void GraphLib::InsertVertexAtRandom() {
	int randomPosition = std::rand() % (numOfVertices + 1);
	InsertVertexAt(std::rand(), randomPosition);
}
void GraphLib::InsertVertexAt(int data, int position)
{
	if (position >= 0 && position <= numOfVertices) {
		
		adjLists[position].push_back(data);

	
		for (int i = 0; i < numOfVertices; ++i) {
			if (i != position) {
				adjLists[i].push_back(data);
				adjLists[position].push_back(i);
			}
		}
	}
	numOfVertices++;

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



int main() {


	GraphLib g(2);
	return 0;
}
