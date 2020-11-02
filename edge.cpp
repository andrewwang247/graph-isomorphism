/*
Representation of a graph edge.

Copyright 2020. Siwei Wang.
*/
#include "edge.h"
#include <algorithm>
#include <functional>
#include <stdexcept>

Edge::Edge(unsigned vert_1_in, unsigned vert_2_in)
    : vert_1(vert_1_in), vert_2(vert_2_in) {}

bool operator==(const Edge& edge_1, const Edge& edge_2) {
  const auto& e1_small = std::min(edge_1.vert_1, edge_1.vert_2);
  const auto& e1_large = std::max(edge_1.vert_1, edge_1.vert_2);
  const auto& e2_small = std::min(edge_2.vert_1, edge_2.vert_2);
  const auto& e2_large = std::max(edge_2.vert_1, edge_2.vert_2);
  return e1_small == e2_small && e1_large == e2_large;
}

bool operator!=(const Edge& edge_1, const Edge& edge_2) {
  return !(edge_1 == edge_2);
}

std::ostream& operator<<(std::ostream& os, const Edge& edge) {
  return os << "{" << std::min(edge.vert_1, edge.vert_2) << ", "
            << std::max(edge.vert_1, edge.vert_2) << "}";
}

std::size_t edge_hash::operator()(const Edge& edge) const {
  const auto h1 = std::hash<unsigned>{}(edge.vert_1);
  const auto h2 = std::hash<unsigned>{}(edge.vert_2);
  return h1 ^ h2;
}

Edge Edge::permute(const std::vector<unsigned>& perm) const {
  const auto v1_iter = std::find(perm.begin(), perm.end(), vert_1);
  const auto v2_iter = std::find(perm.begin(), perm.end(), vert_2);
  if (v1_iter == perm.end() || v2_iter == perm.end()) {
    throw std::runtime_error("Could not compute edge transformation.");
  }
  const auto v1_permuted = static_cast<unsigned>(v1_iter - perm.begin());
  const auto v2_permuted = static_cast<unsigned>(v2_iter - perm.begin());
  return Edge(v1_permuted, v2_permuted);
}
