/*
Representation of a graph edge.

Copyright 2020. Siwei Wang.
*/
#pragma once
#include <functional>
#include <iostream>
#include <vector>

/**
 * A single edge in a graph.
 */
class Edge {
  friend struct edge_hash;

 public:
  const unsigned vert_1;
  const unsigned vert_2;

  /**
   * Initialize edges.
   * @param vert_1_in The value of the first incident vertex.
   * @param vert_2_in The value of the second incident vertex.
   */
  Edge(unsigned vert_1_in, unsigned vert_2_in);
  friend bool operator==(const Edge& edge_1, const Edge& edge_2);
  friend bool operator!=(const Edge& edge_1, const Edge& edge_2);

  /**
   * Applies the permutation to the incident vertices.
   * @param perm The permutation to apply to this.
   * @returns The edge that results from applying perm to this.
   */
  Edge permute(const std::vector<unsigned>& perm) const;

  friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

/**
 * Hash functor for edges.
 */
struct edge_hash {
  std::size_t operator()(const Edge& edge) const;
};
