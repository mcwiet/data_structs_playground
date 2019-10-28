#include "BellmanFord.cpp"
#include <iostream>

using namespace BellmanFord;

int main() {
	std::vector<std::vector<BellmanFord::WeightedEdge>> graph{
		std::vector<WeightedEdge>{ { 1, -1 }, { 2, 4 } },
		std::vector<WeightedEdge>{ { 2, 3 }, { 3, 2 }, { 4, 2 } },
		std::vector<WeightedEdge>{ },
		std::vector<WeightedEdge>{ { 2, 5 }, { 1, 1 } },
		std::vector<WeightedEdge>{ { 3, -3 } },
	};

	for (int i = 0; i < graph.size(); ++i) {
		std::cout << GetShortestDistanceBellmanFord(graph, 0, i) << std::endl;
	}

	return 0;
}