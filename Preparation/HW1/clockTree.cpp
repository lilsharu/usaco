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

vi adj[2501];
vi v;

int cur = 0;
bool visited[2501][2501];

int work(int root, vi& x) {
	visited[cur][root] = true;
	for (auto a : adj[root]) {
		if (!visited[cur][a]) {
			int add = work(a, x);
			x[root] += add;
			x[root] %= 12;
			x[a] = 0;
		}
	}
	return (12 - x[root]) % 12;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("clocktree");

	int n; cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int tot = 0;
	for (cur = 0; cur < n; cur++) {
		vi x = v;
		work(cur, x);
		if (x[cur] == 0 || x[cur] == 1) {
			tot++;
		}
	}

	cout << tot << endl;
}