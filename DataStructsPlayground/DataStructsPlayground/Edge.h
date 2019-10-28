#pragma once
#include "Vertex.h"

namespace Graph {
	class Edge {
	public:
		virtual ~Edge() = default;

	protected:
		Edge(const Vertex& a, const Vertex& b, int weight) : a_(a), b_(b), weight_(weight) {}

		const Vertex& a_;
		const Vertex& b_;
		int weight_;
	};
}