#include "../../template.h"
#include "../trie.h"

typedef vector<char> vc;

bool function_check(int test_cases = 1e3, int MAX_N = 100, int MAX_Q = 1e6) {

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		
		int Q = 1 + rand() % MAX_Q;

		Trie s1;
		unordered_set<string> s2;

		int a, b;
		for(int j = 0; j < Q; j++) {
			int N = 1 + rand() % MAX_N;
			vc word;
			for(int i = 0; i < N; i++) {
				word.push_back(rand()%26 + 'A');
			}
			string w(word.begin(), word.end());
			switch(rand()%2) {
				case 0:
				s1.insert(w);
				s2.insert(w);
				break;
				case 1:
				bool a1 = s1.find(w);
				bool a2 = (s2.find(w) != s2.end());
				if(a1 != a2) {
					cout<<endl<<"Error "<<endl;
					cout<<"word : "<<w<<endl;
					cout<<"q : "<<j<<endl;
					cout<<"Test function value : "<<a1<<endl;
					cout<<"Verify function value : "<<a2<<endl;
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	bool verify = function_check(1e4, 5, 1e5);

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