#include "dGraph.h"

dGraph::dGraph() {
	//Add all the airports to the map with their outgoing edges
	for (auto edge : graphEdges) {
		std::string origin = std::get<0>(edge);
		graphMap[origin].push_back(edge);//Using push_back because is stores a list
	}
}

void dGraph::findDistances(std::string source){
	//Uses Dijkstra's algorithm to find the shortest path from the starting airport
	//to te desired airport

	//Create the heap
	minHeap mHeap(numVertices, source);
	//Mark the node we put in the heap as in it
	isInMinHeap[source] = true;

	//Insert each element into the heap
	for (auto edge : graphMap) {
		if (std::get<0>(edge) == source) {
			//Do nothing 
		}
		else {
			//Insert node into the heap with max initial distance
			mHeap.insert(std::get<0>(edge), MAX_DISTANCE);
			//Mark the node as in the heap
			isInMinHeap[std::get<0>(edge)] = true;
		}
	}

	std::cout << "Initial heap with starting node YYZ" << std::endl;
	mHeap.printHeap();
	std::cout << std::endl;
	std::cout << std::endl;

	//Create a queue for the bfs traversal
	std::list<std::string> bfsQueue;
	std::vector<minHeapNode> poppedNodes;
	std::vector<std::tuple<std::string, int>> parentVertex(numVertices);

	std::cout << "Calculating the distance from " << source << " to each other node!" << std::endl;

	while (!mHeap.isEmpty()) {
		//Remove the min node from the heap and mark it as no longer in the heap
		minHeapNode extractedNode = mHeap.extractMin();
		int currentDistance = extractedNode.getTotalDistance();
		isInMinHeap[extractedNode.getName()] = false;
		poppedNodes.push_back(extractedNode);

		//Push the node into the queue for bfs traversal
		bfsQueue.push_back(extractedNode.getName());

		//Go to all the adjacent elements of our extracted node and process the data
		while (!bfsQueue.empty()) {
			//Pop the first element of the queue
			std::string queueElement = bfsQueue.front();
			//Remove the first element of the queue
			bfsQueue.pop_front();

			//Store the adjacency list of the popped queue element
			std::list<std::tuple<std::string, std::string, int>> aList = graphMap[queueElement];

			//Go through the elements of the adjacency list
			for (auto adjacentElement : aList) {

				//If the current element is in the min heap
				if (isInMinHeap[std::get<1>(adjacentElement)] == true) {

					int currentNodeDistance = std::get<2>(adjacentElement);
					std::vector<minHeapNode> heap = mHeap.getHeap();

					//Get the the adjacent element we are looking at in the heap
					for (auto node : heap) {

						if (node.getName() == std::get<1>(adjacentElement)) {

							//Check if the path to this node costs less than the path we have stored
							if ((currentDistance + std::get<2>(adjacentElement)) < node.getTotalDistance()) {
								//If it is smaller, then udate the distance of the node
								mHeap.updateElement(node.getName(), (currentDistance + std::get<2>(adjacentElement)));
								break;
							}
							else
								break;
						}
					}
				}
			}
		}
	}

	std::cout << std::endl;
	std::cout << "The following is the distances from the origin to every other node" << std::endl;
	for (auto pNodes : poppedNodes) {
		std::cout << pNodes.getName() << " " << pNodes.getTotalDistance() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

//Print out all the airports(vertices) in the map
void dGraph::printAdjacencyList() {
	for (auto city : graphMap) {
		std::string origin = city.first;
		std::cout << origin << ": ";
		std::list<std::tuple<std::string, std::string, int>> neighbours = city.second;
		for (auto c : neighbours) {
			std::cout << " " << std::get<1>(c) << " " << std::get<2>(c) <<",";
		}
		std::cout << std::endl;
	}
}

void dGraph::DFS(std::string startingNodeName) {
	//Mark the starting node as visited
	visited[startingNodeName] = true;
	std::cout << startingNodeName << " ";

	//Get the list stored with key startingNodeName
	std::list<std::tuple<std::string, std::string, int>> aList = graphMap[startingNodeName];
	for (auto adjElement : aList) {
		if (!visited[std::get<1>(adjElement)])
			DFS(std::get<1>(adjElement));
	}

}

void dGraph::BFS(std::string startingNodeName) {
	//Create the queue needed for BFS
	std::list<std::string> bfsQueue;

	//Mark the initial node as visited and place it in the queue
	visited[startingNodeName] = true;
	bfsQueue.push_back(startingNodeName);

	//While our queue is not empty
	while (!bfsQueue.empty()) {
		//Dequeue the first element and print it
		startingNodeName = bfsQueue.front();
		std::cout << startingNodeName << " ";
		bfsQueue.pop_front();

		//Get the adjacent vertices of the vertex we just dequeued.
		//If we have not visited one of the vertices yet, mark it as visited and
		//add it to the queue.
		std::list<std::tuple<std::string, std::string, int>> aList = graphMap[startingNodeName];
		for (auto adjacentElement : aList) {
			if (!visited[std::get<1>(adjacentElement)]) {
				visited[std::get<1>(adjacentElement)] = true;
				bfsQueue.push_back(std::get<1>(adjacentElement));
			}
		}
	}
}

//Go through every airport in the visited map and mark it as not visited
void dGraph::resetVisited() {
	for (auto a : visited) {
		std::string temmAirportName = a.first;
		visited[temmAirportName] = false;
	}
}


