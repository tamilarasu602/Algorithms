#ifndef DISJOINT_SET
#define DISJOINT_SET

#include "../template.h"

class DisjointSet {
	int *parent;
	int *rank;
	int N;

	void join_root(int a, int b) {
		parent[b] = a;
	}
public:
	DisjointSet(int n): N(n) {
		parent = new int[N];
		rank = new int[N];

		for(int i = 0; i < N; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	// ~DisjointSet() {
	// 	delete[] parent;
	// 	delete[] rank;
	// }

	int find(int a) {
		assert(a < N);
		int b = a;
		while (parent[a] != a) {
			a = parent[a];
		}
		while(parent[b] != b) {
			int c = parent[b];
			parent[b] = a;
			b = c;
		}
		return a;
	}

	void join(int a, int b) {
		assert(a < N && b < N);
		int l = find(a);
		int r = find(b);
		if(l == r) {
			return;
		}
		if(rank[l] < rank[r]) {
			join_root(r, l);
		} else {
			join_root(l, r);
			if(rank[r] == rank[l]) {
				rank[l]++;
			}
		}
	}

};

/***********************************************************************

Disjoint Set Data structure Code

USAGE:

	DisjointSet s(N);
	s.join(a, b);
	s.find(a);

PARAMETERS:

	N 		- Maximum number of disjoint sets.
	a, b 	- Must be less than N.

TIME COMPLEXITY:
	
	Query time 			- O(log*N) - Amortized time
	Pre-processing time - O(N)

SPACE COMPLEXITY:
	
	8 * N + 4 bytes

NOTE:
	
	Add code to join_root to handle complex data in an element.

***********************************************************************/

#endif