#ifndef NCR
#define NCR

/***********************************************************************

nCR Code

USAGE:

	unique_ptr<combinations> ncr = make_unique<combinations>();
	ncr.combination(n, r);

NOTE: unique_ptr needed because combinations uses a very large array
and hence needs to be allocated in heap

***********************************************************************/

class combinations {
	static const int PRIME = 1e9 + 7;
	static const int N = 4e6 + 9;

	int product_upto[N];
	int inverse_upto[N];

public:
	combinations() {

		product_upto[0] = 1;
		product_upto[1] = 1;
		inverse_upto[0] = 1;
		inverse_upto[1] = 1;
		
		for(int i = 2; i < N; i++) {
			inverse_upto[i] = ((1LL * inverse_upto[PRIME % i]) * (PRIME - PRIME / i)) % PRIME;  
		}

		for(int i = 2; i < N; i++) {
			product_upto[i] = ((1LL * product_upto[i - 1]) * i) % PRIME;
			inverse_upto[i] = ((1LL * inverse_upto[i - 1]) * inverse_upto[i]) % PRIME;  
		}
	}

	int combination(int n, int r) {
		if(n < 0 || r < 0) return 1;
		if(n < r) return 0;
		
		return ((1LL * product_upto[n]) * (((1LL * inverse_upto[r]) * inverse_upto[n-r])%PRIME)) % PRIME;
	}
};


#endif