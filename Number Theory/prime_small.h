#ifndef PRIME_SMALL
#define PRIME_SMALL

#include "../template.h"

class Prime {
	static const int N = 1e6 + 5;
	static bool prime[N];

public:
	static void init() {
		fill_n(prime, N, true);
		prime[0] = prime[1] = false;

		for(int i = 2; i < N; i++) {
			if(prime[i]) {
				for(int j = 2; j*i < N; j++) {
					prime[j*i] = false;
				}
			}
		}
	}

	static bool isPrime(ll n) {
		assert(n >= 0 && n < N);
		return prime[n];
	}
};
bool Prime::prime[Prime::N];

/***********************************************************************

Determining prime for small numbers

USAGE:

	Prime::init();
	Prime::isPrime(n);

PARAMETERS:

	N 	- 	Max number to be queried + 1.

	n   - 	Must be > 0 and < N

TIME COMPLEXITY:
	
	Query time 			- O(1)
	Pre-processing time - O(N)

SPACE COMPLEXITY:
	
	N + 8 bytes

NOTE: init() must be called before querying. Otherwise
	  state of the program is unknown and wrong.

***********************************************************************/


#endif