#ifndef DISJOINT_SET
#define DISJOINT_SET

#include "../template.h"

class DisjointSet {
	static const int MAX_N = 1e6;
	static int parent[MAX_N];
	static int rank[MAX_N];
public:
	DisjointSet(int N) {
		assert(N <= MAX_N);
		for(int i = 0; i < N; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int a) {
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

	void join_root(int a, int b) {
		parent[b] = a;
	}
};
int DisjointSet::parent[DisjointSet::MAX_N];
int DisjointSet::rank[DisjointSet::MAX_N];

/***********************************************************************

Disjoint Set Data structure Code

USAGE:

	DisjointSet s(N);
	s.join(a, b);
	s.find(a);

PARAMETERS:

	MAX_N 	- 	Maximum number of disjoint sets.

TIME COMPLEXITY:
	
	Query time 			- O(log*N) - Amortized time
	Pre-processing time - O(N)

SPACE COMPLEXITY:
	
	8 * N + 4 bytes

NOTE:
	
	Add code to join_root to handle complex data in an element.

***********************************************************************/

#endif