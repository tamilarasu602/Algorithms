#ifndef DISJOINT_SET
#define DISJOINT_SET

#include "../template.h"

class Trie {
	class Node {
		static const int ALPHABET_SIZE = 26;
	public:
		Node* next[ALPHABET_SIZE];
		bool end = false;
	};

	Node* root;

	inline int toInt(char c) {
		return c - 'A';
	}

public:
	Trie() {
		root = new Node();
	}
	void insert(string& str) {
		Node* ptr = root;
		for(int i = 0; i < str.size(); i++) {
			if(ptr->next[toInt(str[i])] == nullptr) {
				Node *n = new Node();
				ptr->next[toInt(str[i])] = n; 
			}
			ptr = ptr->next[toInt(str[i])];
		}
		ptr->end = true;
	}

	bool find(string& str) {
		Node* ptr = root;
		for(int i = 0; i < str.size(); i++) {
			if(ptr->next[toInt(str[i])] == nullptr) {
				return false;
			}
			ptr = ptr->next[toInt(str[i])];
		}
		return ptr->end;
	}
};


/***********************************************************************

Trie Data structure Code

USAGE:

	Trie words;
	words.insert(word);
	words.find(word);

PARAMETERS:

	ALPHABET_SIZE 	- Max number of different alphabets allowed.

TIME COMPLEXITY:
	
	Query time 			- O(|word|)

SPACE COMPLEXITY:
	
	ALPHABET_SIZE * |Longest word| * 8 bytes

NOTE:
	
	Modify code toInt() to convert char to index.
	Parameters of insert and find could be changed
	to vector<char> without changing the body.

***********************************************************************/

#endif