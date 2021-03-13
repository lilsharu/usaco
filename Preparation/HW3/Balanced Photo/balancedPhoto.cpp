#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
#define f first
#define s second

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("bphoto");

	int n; cin >> n;

	vi v(n);
	vi left, right(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		right[i] = v[i];
	}

	sort(all(right));

	// Test Each Element
	int tot = 0;
	for (int i = 0; i < n; i++) {
		int val = v[i];
		int numLeft = left.end() - upper_bound(left.begin(), left.end(), val);
		int numRight = right.end() - upper_bound(right.begin(), right.end(), val) - numLeft;
		left.insert(upper_bound(left.begin(), left.end(), val), val);
		if (max(numRight, numLeft) > 2 * min(numRight, numLeft)) tot++;
	}

	cout << tot << endl;
}