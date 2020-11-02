/*
Representation of a graph as an edge list.

Copyright 2020. Siwei Wang.
*/
#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
#include "edge.h"

/**
 * Graph theoretic graph as an edge list.
 */
class Graph {
 public:
  std::unordered_set<Edge, edge_hash> edges;
  const unsigned num_vertices;

  /**
   * Initialize empty graph on given number of vertices.
   * @param num_vertices_in The number of vertices that the graph contains.
   */
  explicit Graph(unsigned num_vertices_in);

  /**
   * Add the edge {vert_1, vert_2} to the graph.
   * REQUIRES: vert_1, vert_2 < num_vertices.
   * @param vert_1 The first incident vertex.
   * @param vert_2 The second incident vertex.
   */
  void add_edge(unsigned vert_1, unsigned vert_2);

  /**
   * Applies the permutation to the graph.
   * @param perm The permutation to apply to this.
   * @returns The graph that results from applying perm to this.
   */
  Graph permute(const std::vector<unsigned>& perm) const;

  friend bool operator==(const Graph& g1, const Graph& g2);
  friend bool operator!=(const Graph& g1, const Graph& g2);
  friend std::ostream& operator<<(std::ostream& os, const Graph& gr);
};
