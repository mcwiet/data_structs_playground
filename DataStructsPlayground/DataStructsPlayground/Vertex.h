#pragma once
#include <vector>

namespace Graph {
	class Vertex {
	public:
		explicit Vertex(Vertex& neighbor);
		explicit Vertex(std::reference_wrapper<Vertex> neighbors);

		const std::vector<std::reference_wrapper<Vertex>>& GetNeighbors() const;
		void AddNeighbor(Vertex& neighbor);

	protected:
		std::vector<std::reference_wrapper<Vertex>> neighbors_;
	};
}