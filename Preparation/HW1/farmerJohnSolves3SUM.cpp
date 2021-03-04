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
#define f first
#define s second

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int tot[5000][5000];

// Correct: 1 - 8
// Incorrect: 10
// Timeout: 9 - 15 (excluding 10)
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("threesum");

	int n, q;
	cin >> n >> q;

	vi v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = n; i >= 0; i--) {
		unordered_map<int, int> val;
		for (int k = i + 1; k < n; k++) {
			int needed = -(v[i] + v[k]);
			tot[i][k] += val[needed] + tot[i][k - 1] + tot[i + 1][k] - tot[i + 1][k - 1];
			val[v[k]]++;
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << tot[a][b] << endl;
	}
	return 0;
}