/*
Representation of a graph as an edge list.

Copyright 2020. Siwei Wang.
*/
#include "graph.h"
#include <stdexcept>

Graph::Graph(unsigned num_vertices_in) : num_vertices(num_vertices_in) {}

void Graph::add_edge(unsigned vert_1, unsigned vert_2) {
  if (vert_1 >= num_vertices || vert_2 >= num_vertices) {
    throw std::runtime_error("Edge incidence must be less than |V|.");
  }
  edges.emplace(vert_1, vert_2);
}

Graph Graph::permute(const std::vector<unsigned>& perm) const {
  Graph gr(num_vertices);
  for (const auto& edge : edges) {
    const auto transformed = edge.permute(perm);
    gr.add_edge(transformed.vert_1, transformed.vert_2);
  }
  return gr;
}

bool operator==(const Graph& g1, const Graph& g2) {
  return g1.num_vertices == g2.num_vertices && g1.edges == g2.edges;
}

bool operator!=(const Graph& g1, const Graph& g2) { return !(g1 == g2); }

std::ostream& operator<<(std::ostream& os, const Graph& gr) {
  os << gr.num_vertices << " vertices, " << gr.edges.size() << " edges.\n";
  for (const auto& edge : gr.edges) {
    os << edge << '\n';
  }
  return os;
}
