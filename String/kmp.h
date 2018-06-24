#ifndef KMP
#define KMP

#include "../template.h"

class kmp {
	static const char delimiter = '$';

public:
	static vi find_pattern(const string& pattern, const string& text) {
		vector<int> result, border;
		string d = pattern + delimiter + text;
		int N = pattern.size();
		int M = d.size();

		border.push_back(0);
		int b = 0;
		for(int i = 1; i < M; i++) {
			if (d[i] == d[b]) {
				b = b + 1;
				border.push_back(b);
			}
			else {
				while(b != 0) {
					b = border[b-1];
					if(d[i] == d[b]) {
						b = b + 1;
						border.push_back(b);
						break;
					}
				}
				if(b == 0 && d[i] != d[0]) {
					b = 0;
					border.push_back(b);
				}
			}
		}
		for (int i = N; i < M; i++) {
			if(border[i] == N) {
				result.push_back(i - 2*N);
			}
		}
		return result;
	}
};

/***********************************************************************

KMP - Knuth–Morris–Pratt algorithm

USAGE:

	vi match = kmp::find_pattern(pattern, text);

PARAMETERS:

	delimiter -  Any character that is guaranteed to not appear
				 in text and pattern.

	pattern   -  String to search for.

	text 	  -  String to search in.

TIME COMPLEXITY:
	
	Query time - O(|pattern| + |text|)

SPACE COMPLEXITY:
	
	O(|pattern| + |text|)

***********************************************************************/

#endif