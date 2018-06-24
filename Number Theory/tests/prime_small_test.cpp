#include "../../template.h"
#include "../prime_small.h"

using namespace std;

typedef long long int ll;

class brute_prime {
public:
	static bool isPrime(ll n) {
		if(n < 2) {
			return false;
		}
		for(ll i = 2; i*i <= n; i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
};

bool function_check(int test_cases = 1e6) {

	Prime::init();
	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		ll n = i - 1;
		if(Prime::isPrime(n) != brute_prime::isPrime(n)) {
			cout<<endl<<"Error : "<<endl;
			cout<<"n : "<<n<<endl;
			cout<<"Test function value : "<<Prime::isPrime(n)<<endl;
			cout<<"Verify function value : "<<brute_prime::isPrime(n)<<endl;
			return false;
		}
	}
	return true;
}

int main() {
	bool verify = function_check();

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