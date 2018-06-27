#ifndef SEGMENT_TREE_POINT
#define SEGMENT_TREE_POINT
#include "../template.h"

class SegmentTree {

	class Node {
		int index;
		ll val;

		void assign(int val) {
			this->val = val;
		}

		void merge(Node* tree) {
			this->val = VMAX(tree[2*index].val, tree[2*index + 1].val);
		}

		void update(Node* tree) {
			if(index == 0) return;
			tree[index/2].update(tree);
		}

		void setAnsSelf() {
			ans = val;
		}

		void setAnsNull() {
			ans = 0;
		}

		void setAnsChild(Node* tree, int i) {
			ans = tree[2*index + i].ans;
		}

		void setAnsChildren(Node* tree) {
			ans = VMAX(tree[2*index].ans, tree[2*index + 1].ans);
		}
	public:
		ll ans;

		Node() {}

		void set(Node* tree, int i) {
			this->index = i;
			merge(tree);
		}

		void setLeaf(int i, int v) {
			this->index = i;
			assign(v);
		}

		void replaceLeaf(Node* tree, int v) {
			int old = val;
			if(old != v) {
				assign(v);
				tree[index/2].update(tree);
			}
		}

		void query(Node* tree, int l, int r, int start, int end) {
			if(l <= start && end <= r) {
				setAnsSelf();
				return;
			}
			if(l > end || r < start) {
				setAnsNull();
				return;
			}
			int mid = (start + end)/2;
			if(l > mid) {
				tree[2*index + 1].query(tree, l, r, mid + 1, end);
				setAnsChild(tree, 1);
				return;
			}
			if(r <= mid) {
				tree[2*index].query(tree, l, r, start, mid);
				setAnsChild(tree, 0);
				return;
			}

			tree[2*index].query(tree, l, mid, start, mid);
			tree[2*index+1].query(tree, mid + 1, r, mid + 1, end);
			setAnsChildren(tree);
		}
	};

	Node* tree = NULL;
	int N;

	ll roundup(int n) {
		ll i = 1;
		for(; i < n; i *= 2) {}
		return i;
	}

public:

	SegmentTree(int n, int data[]) {
		N = roundup(n);
		tree = new Node[2*N];

		for(int i = 0; i < N; i++) {
			if(i < n) {
				tree[i + N].setLeaf(i + N, data[i]);
			} else {
				tree[i + N].setLeaf(i + N, 0);
			}
		}

		for(int i = N - 1; i >= 1; i--) {
			tree[i].set(tree, i);
		}
		tree[0].setLeaf(0, 0);
	}

	// ~SegmentTree() {
	// 	delete[] this->tree;
	// }

	void replace(int n, int v) {
		assert(n >= 0 && n < N);
		tree[N + n].replaceLeaf(tree, v);
	}

	ll query(int l, int r) {
		assert(l >= 0 && l < N && r >= 0 && r < N);
		tree[1].query(tree, l, r, 0, N - 1);
		return tree[1].ans;
	}
};

/***********************************************************************

Segment Tree Algorithm - Point Update

USAGE:

	SegmentTree st(N, data);
	s.replace(n, v);
	s.query(l, r);

PARAMETERS:

	N 		- Size of array(data).
	data	- Initial value of array.
	n 		- Position to replace. 0 <= n < N.
	v 		- New value of position n.
	l 		- Query range beginining. Inclusive.
	r 		- Query range end. Inclusive.

TIME COMPLEXITY:
	
	Query time 			- O(log N')
	Pre-processing time - O(N')
	N' 					- Next power of 2 higher than or equal to N

SPACE COMPLEXITY:
	
	2 * N' * Size of Node + 4 bytes

NOTE:
	
	Modify private variable and functions of node to 
	achieve desired result.

	Use destructor if multiple instances need to be created.

***********************************************************************/

#endif