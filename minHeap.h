#pragma once

#include "minHeapNode.h"

#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <map>

//In a min-heap, the parent node is <= the left or right nodes
//The smalles node is the parent node
class minHeap
{
private:
	//Current size of the heap
	int nodeNum;

	//Max size of the heap
	int capacity;

	//Store alements as a vector
	std::vector<minHeapNode> heap;

	//Returns parent index
	int parent(int i) { return (i - 1) / 2; }

	//Returns left child
	int left(int i) { return 2 * i + 1; }

	//Returns right child
	int right(int i) { return 2 * i + 2; }
	

public:
	//Constructor
	minHeap(int, std::string);

	//Insert a key into the min heap
	void insert(std::string, int);

	//Extract the minimum element
	minHeapNode extractMin();

	//Recursively heapify a sub tree
	void heapify(int i);
	//Print the heap

	void printHeap();

	bool isEmpty();

	std::vector<minHeapNode> getHeap();
	
	void updateElement(std::string, int);
	void printMin();
};

