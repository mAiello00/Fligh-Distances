#include "minHeap.h"

//Set heap size and capacity
minHeap::minHeap(int capacity, std::string sourceVertex) {
	nodeNum = 0;
	this->capacity = capacity;
	heap.resize(capacity);
	insert(sourceVertex, 0);
}

//Insert key into the heap
void minHeap::insert(std::string element, int totalDistance) {
	//Check that there is still space in the heap
	if (nodeNum == capacity) {
		std::cout << "Heap is full (in insert)" << std::endl;
		return;
	}

	//Create the node we are inserting into the min-heap
	minHeapNode minNode(element, totalDistance);
	//Increase number of elements in the heap
	nodeNum++;

	//Insert key at the end of the heap (the next valid spot)
	int placement = nodeNum - 1;
	heap[placement] = minNode;

	//Fix the min heap property
	//Swaps elements up until it reaches its correct position
	while (placement != 0 && heap[parent(placement)].getTotalDistance() > heap[placement].getTotalDistance()) {
		std::swap(heap[placement], heap[parent(placement)]);
		placement = parent(placement);
	}
}

void minHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;

	//Find the smallest element of the three
	if ((l < nodeNum) && (heap[l].getTotalDistance() < heap[smallest].getTotalDistance()))
		smallest = l;	
	if ((r < nodeNum) && (heap[r].getTotalDistance() < heap[smallest].getTotalDistance()))
		smallest = r;
	if (smallest != i) {
		std::swap(heap[i], heap[smallest]);
		heapify(smallest);
	}
}

minHeapNode minHeap::extractMin() {
	if (nodeNum == 0) {
		std::cout << "The heap is empty" << std::endl;
		minHeapNode emptyNode("empty", 0);
		return emptyNode;
	}
	else if (nodeNum == 1) {
		nodeNum--;
		return heap[0];
	}
	else {
		//Store the root
		minHeapNode root = heap[0];

		//Maintain heap shape and then order
		heap[0] = heap[nodeNum - 1];
		nodeNum--;
		heapify(0);
		return root;
	}
}

void minHeap::printHeap() {
	int power = 0;
	int value = 1;
	for (int i = 0; i < nodeNum; i++) {
		if (i == value) {
			std::cout << std::endl;
			power += 1;
			value += (1 << power);
		}
		std::cout << heap[i].getName() << " " << heap[i].getTotalDistance() << "  ";
	}
	std::cout << std::endl;
}

bool minHeap::isEmpty() {
	if (nodeNum > 0)
		return false;
	return true;
}

std::vector<minHeapNode> minHeap::getHeap() {
	return heap;
}

void minHeap::updateElement(std::string nodeName, int newDistance) {
	for (int i = 0; i < nodeNum; i++) {
		if (heap[i].getName() == nodeName) {
			std::cout << "Updating the distance of: " << nodeName << " to: " << newDistance << std::endl;
			heap[i].updateTotalDistance(newDistance);
			break;
		}
	}
}

void minHeap::printMin() {
	std::cout << heap[0].getName() << std::endl;
}