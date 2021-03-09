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

vi adj[3001];
int n, m;
vi c;
int root;

vi vis;

int bfs() {
	int tot = 0;
	queue<int> q;
	q.push(root);
	vis[root] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		tot++;
		for (int next : adj[cur]) {
			if (!vis[next]) {
				vis[next] = true;
				q.push(next);
			}
		}
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("closing");

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	c.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i]--;
	}

	root = c[n - 1];
	int exp = n;

	vis.resize(n);

	// BFS Each Removal and check size of component and compare to expected
	for (int i = 0; i < n; i++) {
		fill(all(vis), 0);	
		for (int j = 0; j < i; j++) {
			vis[c[j]] = true;
		}
		
		int x = bfs();
		cout << (x == exp ? "YES" : "NO") << endl;
		exp--;
	}	
}