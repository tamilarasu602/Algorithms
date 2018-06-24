#include <iostream>
#include <cstdlib>
#include "../nCr.h"

using namespace std;

typedef long long int ll;

class BruteCombinations {
	static const int PRIME = 1e9 + 7;
	static const int N = 4e6 + 9;
public:

	static ll fact(int n) {
		ll ans = 1;
		for(int i = 1; i <= n; i++) {
			ans = (ans * i) % PRIME;
		}
		return ans;
	}

	static int compute(int n, int r) {
		if(n < 0 || r < 0) return 1;
		if(n < r) return 0;
		
		ll numer = fact(n);
		ll denom = (fact(n - r) * fact(r))%PRIME;

		return (numer * modInverse(denom)) % PRIME;
	}

	static int modInverse(int b)
	{
	    int x, y;
	    int g = gcdExtended(b, PRIME, x, y);
	 
	    if (g != 1)
	        return -1;
	 
	    return (x%PRIME + PRIME) % PRIME;
	}

	static int gcdExtended(int a, int b, int &x, int &y)
	{
	    // Base Case
	    if (a == 0)
	    {
	        x = 0;
	        y = 1;
	        return b;
	    }
	 
	    int x1, y1; // To store results of recursive call
	    int gcd = gcdExtended(b%a, a, x1, y1);
	 
	    // Update x and y using results of recursive
	    // call
	    x = y1 - (b/a) * x1;
	    y = x1;
	 
	    return gcd;
	}
};

bool function_check(int test_cases = 1e5, int MAX_N = 1e6) {

	Combinations::init();

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int n = 1 + rand() % MAX_N;
		int r = 1 + rand() % MAX_N;
		if(Combinations::compute(n, r) != BruteCombinations::compute(n, r)) {
			cout<<"Error : "<<endl;
			cout<<"n : "<<n<<", r : "<<r<<endl;
			cout<<"Test function value : "<<Combinations::compute(n, r)<<endl;
			cout<<"Verify function value : "<<BruteCombinations::compute(n, r)<<endl;
			return false;
		}
	}
	return true;
}

int main() {
	bool verify = function_check(1e4, 4e6);

	cout<<'\r';
	cout<<"==========================="<<endl;
	if(verify) {
		cout<<"1 Test PASS"<<endl;
	} else {
		cout<<"1 Test Fail"<<endl;
	}
	cout<<"==========================="<<endl;

	return 0;
}