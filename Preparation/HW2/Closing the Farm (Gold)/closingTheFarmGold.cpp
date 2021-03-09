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

#define endl '\n'

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

vi adj[200001];
int n, m;
vi c;
int root;

struct DSU {
	vi e;
	void init(int n) {
		e = vi(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool sameSet(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

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
	DSU d;
	d.init(n);

	vector<bool> vis(n);
	vis[root] = true;
	set<int> notSameSet;

	vector<string> sol(n);
	for (int i = n - 1; i >= 0; i--) {
		for (int next : adj[c[i]]) {
			if (vis[next]) {
				d.unite(c[i], next);
			}
		}
		if (!d.sameSet(root, c[i])) {
			notSameSet.insert(c[i]);
		}
		bool connected = true;
		auto it = notSameSet.begin();
		while (it != notSameSet.end()) {
			if (d.sameSet(*it, root)) {
				it = notSameSet.erase(it);
			} else {
				it++;
				connected = false;
			}
		}

		vis[c[i]] = true;
		sol[i] = (connected ? "YES" : "NO");
	}	

	for (string s : sol) cout << s << endl;
}