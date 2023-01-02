#include "dGraph.h"

#include <iostream>

int main()
{
	dGraph* graph = new dGraph();

	std::cout << "This is the adjacency list that represents the graph:" << std::endl;
	graph->printAdjacencyList();
	std::cout << std::endl;

	std::cout << "This is the BFS traversal of the graph starting at YYZ airport:" << std::endl;
	graph->BFS("YYZ");
	graph->resetVisited();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "This is the DFS traversal ofthe graph starting at YYZ airport:" << std::endl;
	graph->DFS("YYZ");
	graph->resetVisited();
	std::cout << std::endl;
	std::cout << std::endl;

	graph->findDistances("YYZ");	
}