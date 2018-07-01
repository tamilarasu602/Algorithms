#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// utility functions
#define ARGMAX(a, b, c, d) (((a) > (b)) ? (c) : (d))
#define ARGMIN(a, b, c, d) (((a) < (b)) ? (c) : (d))
#define VMAX(a, b) ARGMAX(a, b, a, b)
#define VMIN(a, b) ARGMIN(a, b, a, b)

// Modulo functions
#define MODULO 1000000007
#define ADDM(a, b, mod) (((1LL * (a)) + (b))%(mod))
#define ADD(a, b) ADDM(a, b, MODULO)
#define SUBM(a, b, mod) (((1LL * (a)) - (b) + (mod))%(mod))
#define SUB(a, b) SUBM(a, b, MODULO)
#define MULM(a, b, mod) (((1LL * (a)) * (b))%(mod))
#define MUL(a, b) MULM(a, b, MODULO)

#define FOR(i, n) for(ll i = 0; i < n; i++)
#define FORA(i, s, e) for(ll i = s; i <= e; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);



	return 0;
}