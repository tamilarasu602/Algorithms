#include "../../template.h"
#include "../sparse_table.h"
#include "../segment_tree_point.h"

class BruteMax {
	vi data;
public:
	BruteMax(int n, int data[]) {
		this->data.resize(n, 0);
		for(int i = 0; i < n; i++) {
			this->data[i] = data[i];
		}
	}

	int query(int l, int r) {
		int max = 0;
		for(int i = l; i <= r; i++) {
			max = VMAX(max, data[i]);
		}
		return max;
	}
};

bool function_check_1(int test_cases = 1e3, int MAX_N = 1e5, int MAX_Q = 1e6) {

	int MAX_V = 1e8;

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 1 + rand() % MAX_N;
		int Q = 1 + rand() % MAX_Q;

		int* data = new int[N];
		for(int i = 0; i < N; i++) {
			data[i] = 1 + rand()%MAX_V;
		}

		SparseTable s1(N, data);
		BruteMax s2(N, data);

		int a, b;
		for(int j = 0; j < Q; j++) {
			a = rand()%N;
			b = rand()%N;
			int temp = VMIN(a, b);
			b = VMAX(a, b);
			a = temp;
			int a1 = s1.query(a, b);
			int a2 = s2.query(a, b);
			if(a1 != a2) {
				cout<<endl<<"Error : "<<endl;
				cout<<"n : "<<N<<endl;
				cout<<"q : "<<j<<endl;
				cout<<a<<" "<<b<<endl;
				cout<<"Test function value : "<<a1<<endl;
				cout<<"Verify function value : "<<a2<<endl;
				return false;
			}
		}

		delete[] data;
	}
	return true;
}

bool function_check_2(int test_cases = 1e3, int MAX_N = 1e5, int MAX_Q = 1e6) {

	int MAX_V = 1e8;

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 1 + rand() % MAX_N;
		int Q = 1 + rand() % MAX_Q;

		int* data = new int[N];
		for(int i = 0; i < N; i++) {
			data[i] = 1 + rand()%MAX_V;
		}

		SparseTable s1(N, data);
		SegmentTree s2(N, data);

		int a, b;
		for(int j = 0; j < Q; j++) {
			a = rand()%N;
			b = rand()%N;
			int temp = VMIN(a, b);
			b = VMAX(a, b);
			a = temp;
			int a1 = s1.query(a, b);
			int a2 = s2.query(a, b);
			if(a1 != a2) {
				cout<<endl<<"Error : "<<endl;
				cout<<"n : "<<N<<endl;
				cout<<"q : "<<j<<endl;
				cout<<a<<" "<<b<<endl;
				cout<<"Test function value : "<<a1<<endl;
				cout<<"Verify function value : "<<a2<<endl;
				return false;
			}
		}

		delete[] data;
	}
	return true;
}

int main() {
	bool verify = function_check_1(1e4, 1e4, 1e5);

	cout<<'\r';
	cout<<"==========================="<<endl;
	if(verify) {
		cout<<"Test 1: PASS"<<endl;
	} else {
		cout<<"Test 1: Fail"<<endl;
	}
	cout<<"==========================="<<endl;

	verify = function_check_2(1e2, 5e5, 1e5);

	cout<<'\r';
	cout<<"==========================="<<endl;
	if(verify) {
		cout<<"Test 2: PASS"<<endl;
	} else {
		cout<<"Test 2: Fail"<<endl;
	}
	cout<<"==========================="<<endl;

	return 0;
}