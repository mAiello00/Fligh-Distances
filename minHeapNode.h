#pragma once
#include <string>

//Represents a node in the min heap
class minHeapNode
{
private:
	std::string nodeName;
	int totalDistance;

public:
	minHeapNode(std::string, int);
	minHeapNode();
	std::string getName() { return nodeName; }
	int getTotalDistance() { return totalDistance; }
	void updateTotalDistance(int);
};

