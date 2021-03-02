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

#define endl '\n'


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	int val[n];

	for (int i = 0; i < n; i++) {
		val[i] = s[i] - 'A';
	}

	vi ps, ss;
	ps.resize(n + 1), ss.resize(n + 2);

	int minBefore[26];
	for (int i = 0; i < 26; i++) minBefore[i] = 30;
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + minBefore[val[i]] < val[i] ? 1 : 0;
		for (int j = 0; j < 26; j++) {
			minBefore[j] = min(minBefore[j], val[i]);
		}
	}
	for (int i = 0; i < 26; i++) minBefore[i] = 30;

}