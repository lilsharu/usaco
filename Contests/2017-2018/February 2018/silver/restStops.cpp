#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define ffor(i,a,b) for (int i = (a); i < (b); ++i)
#define ff0r(i,a) ffor(i,0,a)
#define rrof(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rr0f(i,a) rrof(i,0,a)
#define trav(a,x) for (auto& a: x)
#define fforn ff0r(i, n)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

// Strategy: Greedy
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("reststops");

	ll l, n, f, b;
	cin >> l >> n >> f >> b;

	ll mult = f - b;

	vll p, c;
	p.resize(n), c.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> c[i];
	}

	vll go;
	ll cMax = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (c[i] > cMax) {
			cMax = c[i];
			go.pb(i);
		}
	}
	
	ll tot = 0, cp = 0;
	for (int i = go.size() - 1; i >= 0; i--) {
		int dest = p[go[i]];
		int dist = dest - cp;
		tot += mult * dist * c[go[i]];
		cp = dest;
	}

	cout << tot << endl;
}