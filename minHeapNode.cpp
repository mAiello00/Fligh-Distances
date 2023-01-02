#include "minHeapNode.h"

minHeapNode::minHeapNode() {
	this->nodeName = "empty";
	this->totalDistance = 0;
}

minHeapNode::minHeapNode(std::string nodeName, int totalDistance) {
	this->nodeName = nodeName;
	this->totalDistance = totalDistance;
}

void minHeapNode::updateTotalDistance(int newDistance) {
	this->totalDistance = newDistance;
}