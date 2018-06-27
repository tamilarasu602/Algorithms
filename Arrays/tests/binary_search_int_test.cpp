#include "../../template.h"
#include "../binary_search_int.h"

template <typename F>
int bruteSearch(int start, int end, F f) {
	for(int i = start; i <= end; i++) {
		if(f(i)) {
			if(i == start) return -1;
			else return i - 1;
		}
	}
	return -1;
};

vi data;
int target;
bool check(int i) {
	if(data[i] <= target) return false;
	else return true;
}

bool function_check(int test_cases = 1e3, int MAX_N = 1e5, int MAX_Q = 1e6) {

	int MAX_V = 1e8;

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 2 + rand() % MAX_N;
		int Q = 1 + rand() % MAX_Q;

		data.clear();
		data.resize(N, 0);
		for(int i = 0; i < N; i++) {
			data[i] = 1 + rand()%MAX_V;
		}
		sort(data.begin(), data.end());

		int a, b;
		for(int j = 0; j < Q; j++) {
			b = 1 + rand()%(N - 1);
			a = rand()%b;
			target = rand()%MAX_V;
			int a1 = binarySearch(a, b, check);
			int a2 = bruteSearch(a, b, check);
			if(a1 != a2) {
				cout<<endl<<"Error : "<<endl;
				cout<<"n : "<<N<<endl;
				cout<<"q : "<<j<<endl;
				cout<<a<<" "<<b<<" "<<target<<endl;
				cout<<data[a]<<" "<<data[b]<<endl;
				cout<<"Test function value : "<<a1<<endl;
				cout<<"Verify function value : "<<a2<<endl;
				return false;
			}
		}
	}
	return true;
}

int main() {
	bool verify = function_check(1e4, 1e4, 1e5);

	cout<<'\r';
	cout<<"==========================="<<endl;
	if(verify) {
		cout<<"Test 1: PASS"<<endl;
	} else {
		cout<<"Test 1: Fail"<<endl;
	}
	cout<<"==========================="<<endl;

	return 0;
}