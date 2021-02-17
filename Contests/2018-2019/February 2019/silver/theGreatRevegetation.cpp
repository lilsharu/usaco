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

int pv[100001];
vi same[100001], dif[100001];

bool poss = true;

void search(int i, int v) {
	pv[i] = v;
	for (auto a : same[i]) {
		if (pv[a] == 3 - v) poss = false;
		else if (pv[a] == 0) search(a, v);
	}
	
	for (auto a : dif[i]) {
		if (pv[a] == v) poss = false;
		else if (pv[a] == 0) search(a, 3 - v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	setIO("revegetate");

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char s;
		int a, b;
		cin >> s >> a >> b;
		a--, b--;

		if (s == 'S') {
			same[a].pb(b);
			same[b].pb(a);
		} else {
			dif[a].pb(b);
			dif[b].pb(a);
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!pv[i]) {
			search(i, 1);
			count++;
		}
	}

	if (!poss) {
		cout << 0 << endl;	
		return 0;
	}

	cout << 1;
	while (count--) cout << 0;	
	cout << endl;
	return 0;
}