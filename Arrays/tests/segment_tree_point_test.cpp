#include "../../template.h"
#include "../segment_tree_point.h"

class BruteSegmentTree {
	int* data;
	int N;
public:
	BruteSegmentTree(int N, int data[]) {
		this->N = N;
		this->data = new int[N];
		for(int i = 0; i < N; i++) {
			this->data[i] = data[i];
		}
	}

	~BruteSegmentTree() {
		delete[] this->data;
	}

	void replace(int n, int v) {
		this->data[n] = v;
	}

	int query(int l, int r) {
		int max = 0;
		for(int i = l; i <= r; i++) {
			max = VMAX(max, data[i]);
		}
		return max;
	}
};


bool function_check(int test_cases = 1e3, int MAX_N = 1e5, int MAX_Q = 1e6) {

	int MAX_V = 1e8;

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 1 + rand() % MAX_N;
		int Q = 1 + rand() % MAX_Q;

		int* data = new int[N];
		for(int i = 0; i < N; i++) {
			data[i] = 1 + rand()%MAX_V;
		}

		SegmentTree s1(N, data);
		BruteSegmentTree s2(N, data);

		int a, b;
		for(int j = 0; j < Q; j++) {
			switch(rand()%2) {
				case 0:
				a = rand()%N;
				b = rand()%MAX_V;
				s1.replace(a, b);
				s2.replace(a, b);
				break;
				case 1:
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
		}

		delete[] data;
	}
	return true;
}

int main() {
	bool verify = function_check(1e4, 1e5, 1e4);

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