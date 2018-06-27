#ifndef SPARSE_TABLE
#define SPARSE_TABLE

#include "../template.h"

class SparseTable {
	// const static int MAXN = 1e6;
	// const static int LOGN = 22;
	// int table[MAX_N][LOGN];
	vvi table;
	int N;

	int compute(int a, int b) {
		return VMAX(a, b);
	}

	int log_2(int n) {
		int i = 0;
		for(ll base = 1; base < n; i++, base = base * 2);
		return i;
	} 

	ll power_2(int a) {
		ll ans = 1;
		for(int i = 0; i < a; i++, ans*=2);
		return ans;
	}

	public:
	SparseTable(int n, int data[]) {
		N = n;
		table.resize(n, vi(log_2(n) + 1, 0));

		for(int i = 0; i < n; i++) {
			table[i][0] = data[i];
		}

		for(int p = 1; p <= log_2(n); p++) {
			int half = power_2(p-1);
			for(int i = 0; i + half + 1 < n; i++) {
				table[i][p] = compute(table[i][p-1], table[i + half][p-1]);
			}
		}
	}

	int query(int l, int r) {
		assert(l >= 0 && r >= 0 && l <= r && l < N && r < N);
		if(l == r) {
			return table[l][0];
		}
		int len = r - l + 1;
		int p = log_2(len);

		return compute(table[l][p - 1], table[r - power_2(p - 1)][p - 1]);
	}
};

/***********************************************************************

Sparse Table Algorithm

USAGE:

	SparseTable s(N, data);
	s.query(l, r);

PARAMETERS:

	N 		- Size of array(data).
	data	- Initial value of array.
	l 		- Query range beginining. Inclusive.
	r 		- Query range end. Inclusive.

TIME COMPLEXITY:
	
	Query time 			- O(1)
	Pre-processing time - O(N * log(N))

SPACE COMPLEXITY:
	
	4 * N * log(N) + 4 bytes

NOTE:
	
	Modify the function compute depending on question.
	Data a, b may belong to overlapped regions.

***********************************************************************/

#endif