#pragma once

#include "minHeap.h"

#include <vector>
#include <list>
#include <utility>
#include <string>
#include <tuple>
#include <iostream>
#include <map>

class dGraph
{
private:
	//Initial set of edges
	std::vector<std::tuple<std::string, std::string, int>> graphEdges = 
	{
			{"YYZ", "SFO", 2},
			{"YYZ", "HND", 10},
			{"YYZ", "BUD", 4},
			{"HND", "YYZ", 11},
			{"HND", "AMS", 15},
			{"SFO", "BUD", 8},
			{"BUD", "YYZ", 4},
			{"BUD", "DME", 3},
			{"AMS", "BUD", 1},
			{"AMS", "DME", 4},
			{"DME", "FRA", 3},
			{"FRA", "DME", 2},
			{"FRA", "AMS", 1}
	};

	std::vector<std::string> codes = {"YYZ", "HND", "SFO", "BUD", "AMS", "DME", "FRA"};
	std::map<std::string, std::list<std::tuple<std::string, std::string, int>>> graphMap;
	std::map<std::string, bool> visited;
	//Stores a bool value to tell us if the specifid element is in the heap
	std::map<std::string, bool> isInMinHeap;
	//Number of vertices in the graph
	int numVertices = 7;

	int MAX_DISTANCE = 9999999;

public:
	dGraph();
	void findDistances(std::string);
	void printAdjacencyList();
	void DFS(std::string);
	void BFS(std::string);
	void resetVisited();
};