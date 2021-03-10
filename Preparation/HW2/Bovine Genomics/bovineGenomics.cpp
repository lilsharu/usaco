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

vector<string> spot;
vector<string> plan;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("cownomics");

	int n, m;
	cin >> n >> m;

	spot.resize(n);
	plan.resize(n);

	for (int i = 0; i < n; i++) cin >> spot[i];
	for (int i = 0; i < n; i++) cin >> plan[i];

	int mingap = m;
	// Test Each substring
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < min(mingap, m - i); j++) {
			unordered_set<string> spst;
			for (string s : spot) {
				spst.insert(s.substr(i, j));
			}
			bool found = true;
			for (string s : plan) {
				if (spst.count(s.substr(i, j))) {
					found = false;
					break;
				}
			}
			if (found) {
				mingap = min(mingap, j);
				break;
			}
		}
	}

	cout << mingap << endl;
}