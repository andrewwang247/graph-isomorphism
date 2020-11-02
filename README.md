# Graph Isomorphism

Brute-force solver for the graph isomorphism problem.

Usage: `./isomorphic {graph_A} {graph_B}` where `graph_A` and `graph_B` are file paths.

The graph files should have the following format. See the `Test` directory for examples.

```text
{num_vertices}
{edge_1_vert_1} {edge_1_vert_2}
...
{edge_num_vertices_vert_1} {edge_num_vertices_vert_2}
```

## Representation

The vertices of the graph are represented by a set V = {0, ..., `num_vertices` - 1}. A `Graph` is represented as an `Edge` set, where each `Edge` is given by an *unordered* pair of elements from V. That is, two edges are the same if they have the same incident vertices, regardless of how those vertices were designated as vertex 1 and 2.

A permutation p of the set V transforms an `Edge` e = (a, b) into p(e) = (p(a), p(b)). We can extend this permutation of p to a `Graph` g by taking the pointwise transformation of the edges of g. That is, E(p(g)) = p(E(g)) = {p(e) : e in E(g)}.

## Algorithm

Assuming that the number of vertices and edges in two graphs are the same, we search for an isomorphism by iterating over permutations of `num_vertices` elements. A permutation represents a possible isomorphism between the two graphs. Apply each permutation to the first graph and check for equality with the second graph. Two `Graph` objects are equal if and only if they have the same number of vertices and their edge sets are equal.

If an isomorphism exists, the algorithm will find it and print the first isomorphism that it finds while looping through `std::vector {0, ..., num_vertices - 1}` with `std::next_permutation`. Otherwise, the program states that the graphs are not isomorphic.

## Testing

In the `Test` directory, the graphs `nope*.txt` are pairwise non-isomorphic while the graphs `yup*.txt` are isomorphic. Example output is shown below.

```text
$ ./isomorphic Test/nope1.txt Test/nope2.txt
Graph A: 10 vertices, 15 edges.
{6, 8}
{7, 9}
{7, 8}
{5, 9}
{4, 9}
{3, 8}
{5, 6}
{1, 2}
{0, 1}
{2, 3}
{1, 6}
{3, 4}
{0, 4}
{2, 7}
{0, 5}

Graph B: 10 vertices, 15 edges.
{7, 8}
{5, 9}
{4, 9}
{3, 8}
{5, 6}
{1, 2}
{6, 7}
{8, 9}
{0, 1}
{2, 3}
{1, 6}
{3, 4}
{0, 4}
{2, 7}
{0, 5}

Graphs A and B are not isomorphic.
```

```text
$ ./isomorphic Test/yup0.txt Test/yup1.txt
Graph A: 6 vertices, 6 edges.
{3, 4}
{2, 5}
{4, 5}
{0, 1}
{0, 3}
{1, 2}

Graph B: 6 vertices, 6 edges.
{0, 3}
{1, 3}
{0, 2}
{2, 5}
{4, 5}
{1, 4}

Isomorphism A -> B: 0 2 3 1 5 4
```
