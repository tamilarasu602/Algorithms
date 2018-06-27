#ifndef BINARY_SEARCH
#define BINARY_SEARCH

template <typename F>
int binarySearch(int start, int end, F f) {
	assert(start <= end);
	if(!f(end) || f(start)) {
		return -1;
	}
	while(start < end) {
		int mid = (start + end + 1)/2;
		if(f(mid)) {
			end = mid - 1;
		} else {
			start = mid;
		}
	}
	return start;
}

/***********************************************************************

Binary Search Algorithm

USAGE:

	int ans = binarySearch(start, end, f);

PARAMETERS:

	start 	- Query range beginining. Inclusive.
	end 	- Query range end. Inclusive.
	f 		- function that will be called with an integer.

TIME COMPLEXITY:
	
	Query time 			- O(log(end - start + 1))

NOTE:
	
	The function must be monotonous and 
	f(start) = false and f(end) = true

***********************************************************************/

#endif