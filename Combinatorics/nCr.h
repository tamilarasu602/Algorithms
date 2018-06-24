#ifndef NCR
#define NCR

class Combinations {
	static const int PRIME = 1e9 + 7;
	static const int N = 4e6 + 9;

	static int product_upto[N];
	static int inverse_upto[N];

public:
	static void init() {

		product_upto[0] = 1;
		product_upto[1] = 1;
		inverse_upto[0] = 1;
		inverse_upto[1] = 1;
		
		for(int i = 2; i < N; i++) {
			inverse_upto[i] = ((1LL * inverse_upto[PRIME % i]) * 
									(PRIME - PRIME / i)) % PRIME;  
		}

		for(int i = 2; i < N; i++) {
			product_upto[i] = ((1LL * product_upto[i - 1]) * i) % PRIME;
			inverse_upto[i] = ((1LL * inverse_upto[i - 1]) * inverse_upto[i]) % PRIME;  
		}
	}

	static int compute(int n, int r) {
		if(n < 0 || r < 0) return 1;
		if(n < r) return 0;
		
		return ((1LL * product_upto[n]) * 
			(((1LL * inverse_upto[r]) * inverse_upto[n-r])%PRIME)) % PRIME;
	}
};
int Combinations::product_upto[Combinations::N];
int Combinations::inverse_upto[Combinations::N];

/***********************************************************************

nCR Code

USAGE:

	Combinations::init();
	Combinations::compute(n, r);

PARAMETERS:

	PRIME - Usually this is 1e9 + 7 in most problems.
			This is equal to the modulo with which the 
			answer must be printed.

	N 	  - This should be equal to the max value of
			n in nCr.
	
	n, r  - n, r of nCr.

TIME COMPLEXITY:
	
	Query time 			- O(1)
	Pre-processing time - O(N)

SPACE COMPLEXITY:
	
	16 * N + 8 bytes

NOTE: Must call init() before any call to compute().

***********************************************************************/

#endif