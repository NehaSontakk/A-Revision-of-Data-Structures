# Union Find and Dynamic Connectivity

Goal: Design efficient data structure for union-find.

Number of objects N can be huge. 

Number of operations M can be huge.

Find queries and union commands may be intermixed.

Quick find: complextity of: initialization = N, Union = N,find operation = 1

Quick union: complexity of: initialization = N, Union = N,find operation = N

weighted quick union : N, log(N), log(N)

Applications of union operations: 
* Percolation games
  * Games (Go, Hex).
* Dynamic connectivity
  * Kruskal's minimum spanning tree algorithm
  * Least common ancestor.
