#include "../../template.h"
#include "../disjoint_set.h"

class BruteDisjointSet {
	static const int MAX_N = 1e6;
	static int parent[MAX_N];
	int N;
public:
	BruteDisjointSet(int N) {
		assert(N <= MAX_N);
		this->N = N;
		for(int i = 0; i < N; i++) {
			parent[i] = i;
		}
	}

	int find(int a) {
		return parent[a];
	}

	void join(int a, int b) {
		a = parent[a];
		b = parent[b];
		for(int i = 0; i < N; i++) {
			if(parent[i] == b) {
				parent[i] = a;
			}
		}
	}
};
int BruteDisjointSet::parent[BruteDisjointSet::MAX_N];

bool function_check(int test_cases = 1e3, int MAX_N = 1e5, int MAX_Q = 1e6) {

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 1 + rand() % MAX_N;
		int Q = 1 + rand() % MAX_Q;

		DisjointSet s1(N);
		BruteDisjointSet s2(N);

		int a, b;
		for(int j = 0; j < Q; j++) {
			switch(rand()%2) {
				case 0:
				a = rand()%N;
				b = rand()%N;
				s1.join(a, b);
				s2.join(a, b);
				break;
				case 1:
				a = rand()%N;
				b = rand()%N;
				if(((s1.find(a) == s1.find(b)) && (s2.find(a) != s2.find(b))) ||
				   ((s1.find(a) != s1.find(b)) && (s2.find(a) == s2.find(b)))) {
					cout<<endl<<"Error : "<<endl;
					cout<<"n : "<<N<<endl;
					cout<<"q : "<<j<<endl;
					cout<<a<<" "<<b<<endl;
					cout<<"Test function value : "<<(s1.find(a) == s1.find(b))<<endl;
					cout<<"Verify function value : "<<(s2.find(a) == s2.find(b))<<endl;
					return false;
				}
			}
		}
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