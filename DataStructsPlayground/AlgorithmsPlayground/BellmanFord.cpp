#include <vector>
#include <limits>

namespace BellmanFord {
	struct WeightedEdge {
		WeightedEdge(int v, int w) : vertex(v), weight(w) {};
		const int vertex;
		const int weight;
	};

	int GetShortestDistanceBellmanFord(const std::vector<std::vector<WeightedEdge>>& graph, int start, int end) {
		// Create initial list of paths and set all distances to 'infinity' except for starting node
		std::vector<int> shortest_path(graph.size(), std::numeric_limits<int>::max());
		shortest_path[start] = 0;

		// Iterate over the vertices v-1 times
		for (int i = 1; i < graph.size(); ++i) {
			for (int v = 0; v < graph.size(); ++v) {
				// For each vertex, calculate the shortest distance to each neighboring vertex
				for (int e = 0; e < graph[v].size(); ++e) {
					if ((shortest_path[v] != std::numeric_limits<int>::max()) && (shortest_path[v] + graph[v][e].weight < shortest_path[graph[v][e].vertex]))
						shortest_path[graph[v][e].vertex] = shortest_path[v] + graph[v][e].weight;
				}
			}
		}

		return shortest_path[end];
	}
}