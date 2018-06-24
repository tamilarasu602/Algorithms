#ifndef PRIME
#define PRIME

#include "../template.h"

class Prime {
	static const int N = 1e6;
	static bool prime[N];
	static int primeList[N];
	static int count;

public:
	static void init() {
		fill_n(prime, N, true);
		prime[0] = prime[1] = false;

		for(int i = 2; i < N; i++) {
			if(prime[i]) {
				primeList[count++] = i;
				for(int j = 2; j*i < N; j++) {
					prime[j*i] = false;
				}
			}
		}
	}

	static bool isPrime(ll n) {
		assert(n >= 0 && n < (1LL * N)*N);
		if(n < N) {
			return prime[n];
		} else {
			for(int i = 0; i < count; i++) {
				if(n % primeList[i] == 0) {
					return false;
				} else if(primeList[i] * primeList[i] > n) {
					return true;
				}
			}
			return true;
		}
	}
};
bool Prime::prime[Prime::N];
int Prime::primeList[Prime::N];
int Prime::count = 0;

/***********************************************************************

Determining prime for large numbers

USAGE:

	Prime::init();
	Prime::isPrime(n);

PARAMETERS:

	N 	- 	This must be equal to the square root
			of the maximum number for which primeness
			needs to be determined

	n   - 	Must be > 0 and < N * N

TIME COMPLEXITY:
	
	Query time 			- O(1)			for n < N
						- O(N/log(N)) 	for n >= N
	Pre-processing time - O(N)

SPACE COMPLEXITY:
	
	5 * N + 8 bytes

NOTE: init() must be called before querying. Otherwise
	  state of the program is unknown and wrong.

***********************************************************************/

#endif