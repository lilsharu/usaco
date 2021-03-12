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

#define ts to_string

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

// Principal of Inclusion and Exclusion
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("cowpatibility");

	int n;
	cin >> n;

	vector<map<string, vi>> m(5);

	vi num(5);
	for (int i = 0; i < n; i++) {
		vi v(5);
		for (int j = 0; j < 5; j++) {
			cin >> v[j];
		}

		sort(all(v));

		for (int j = 0; j < n; j++) {
			m[0][ts(v[j])].pb(i);
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				m[1][ts(v[j]) + ":" + ts(v[k])].pb(i);
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; h++) {
					m[2][ts(v[j]) + ":" + ts(v[k]) + ":" + ts(v[l])].pb(i);
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					for (int o = l + 1; o < n; o++) {
						m[3][ts(v[j]) + ":" + ts(v[k]) + ":" + ts(v[l]) + ":" + ts(v[o])].pb(i);
					}
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					for (int o = l + 1; o < n; o++) {
						for (int p = o + 1; p < n; p++) {
							m[4][ts(v[j]) + ":" + ts(v[k]) + ":" + ts(v[l]) + ":" + ts(v[o]) + ":" + ts(v[p])].pb(i);
						}
					}
				}
			}
		}
	}
}