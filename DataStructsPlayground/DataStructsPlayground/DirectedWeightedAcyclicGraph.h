#pragma once
#include "Edge.h"

namespace Graph {
	class DirectedWeightedEdge : public Edge {
	public:
		DirectedWeightedEdge(const Vertex& origin, const Vertex& destination, int weight) : Edge(origin, destination, weight), weight_(weight) {};
		inline int Weight() const { return weight_; };
		inline const Vertex& Origin() const { return a_; };
		inline const Vertex& Destination() const { return b_; }

		virtual ~DirectedWeightedEdge() = default;
	private:
		int weight_;
	};
}