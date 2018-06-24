#include "../../template.h"
#include "../kmp.h"

class brute_match {
public:
	static vi find_pattern(const string& pattern, const string& text) {
		vi answer;
		int N = pattern.size();
		int M = text.size();
		for(int i = 0; i <= M - N; i++) {
			answer.push_back(i);
			for(int j = 0; j < N; j++) {
				if(pattern[j] != text[i + j]) {
					answer.pop_back();
					break;
				}
			}
		}
		return answer;
	}
};

bool function_test(int MAX_N = 1e6, int test_cases = 1e4, int char_size = 26) {

	for(int i = 1; i <= test_cases; i++) {
		cout<<"\rTest Progress : "<<(100.0 * i)/test_cases<<"%"<<flush;
		int N = 1 + rand()%MAX_N;
		int M = 1 + rand()%MAX_N;
		char* p = new char[N + 1];
		char* t = new char[M + 1];
 
		for(int i = 0; i < N; i++) {
			p[i] = 'a' + rand() % char_size;
		}
		p[N] = 0;

		for(int i = 0; i < M; i++) {
			t[i] = 'a' + rand() % char_size;
		}
		t[M] = 0;

		string pattern(p), text(t);

		vi a1 = kmp::find_pattern(pattern, text);
		vi a2 = brute_match::find_pattern(pattern, text);

		if(a1.size() != a2.size()) {
			cout<<endl<<"Error : Result size mismatch"<<endl;
			cout<<"Pattern : "<<pattern<<endl;
			cout<<"Text : "<<text<<endl;
			cout<<"KMP Count : "<<a1.size()<<endl;
			cout<<"Verify solution count : "<<a2.size()<<endl;
			return false;
		}

		for(int i = 0; i < a1.size(); i++) {
			if(a1[i] != a2[i]) {
				cout<<endl<<"Error : Result mismatch"<<endl;
				cout<<"Pattern : "<<pattern<<endl;
				cout<<"Text : "<<text<<endl;
				cout<<"Mismatch Location : "<<a1[i]<<" "<<a2[i]<<endl;
				return false;
			}
		}
		delete[] p;
		delete[] t;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool verify = function_test(1e5, 1e5);

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