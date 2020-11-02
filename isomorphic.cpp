/*
Driver program.

Copyright 2020. Siwei Wang.
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include "graph.h"

/**
 * Read a graph from a file.
 * @param filename The path to the file that stores the graph.
 * @returns The graph specified by filename.
 */
Graph read_graph_from(const char* filename) {
  std::ifstream fp(filename);
  unsigned num_vertices;
  fp >> num_vertices;
  Graph gr(num_vertices);
  for (unsigned v1, v2; fp >> v1 >> v2;) {
    gr.add_edge(v1, v2);
  }
  return gr;
}

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned>& perm) {
  for (auto idx : perm) os << idx << ' ';
  return os;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  if (argc != 3) {
    throw std::runtime_error("Expected 2 positional arguments.");
  }

  const auto gr_a = read_graph_from(argv[1]);
  const auto gr_b = read_graph_from(argv[2]);

  std::cout << "Graph A: " << gr_a << "\nGraph B: " << gr_b << std::endl;

  if (gr_a.num_vertices != gr_b.num_vertices ||
      gr_a.edges.size() != gr_b.edges.size()) {
    std::cout << "Graphs A and B are not isomorphic.\n";
    return 0;
  }

  std::vector<unsigned> perm(gr_a.num_vertices);
  std::iota(perm.begin(), perm.end(), 0);

  do {
    const auto gr_t = gr_a.permute(perm);
    if (gr_t == gr_b) {
      std::cout << "Isomorphism A -> B: " << perm << '\n';
      return 0;
    }
  } while (std::next_permutation(perm.begin(), perm.end()));

  std::cout << "Graphs A and B are not isomorphic.\n";
}
