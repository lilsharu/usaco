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

pii pos[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("fenceplan");
	
	int n, m;
	cin >> n >> m;
	
	DSU d;
	// d.init(n);

	for (int i = 0; i < n; i++) {
		cin >> pos[i].f >> pos[i].s;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		// d.unite(a, b);
	}
	
	map<int, vector<int>> mp;
	
	for (int i = 0; i < n; i++) {
		int x = i;//d.get(i);
		mp[x].pb(i);
	}

	int minp = 4e8 + 1;
	for (auto const& x : mp) {
		sort(all(x.s));
		int maxx = -1, maxy = -1, minx = 1e8 + 1, miny = 1e8 + 1;
		for (auto a : x.s) {
			if (pos[a].f < minx) minx = pos[a].f;
			if (pos[a].f > maxx) maxx = pos[a].f;
			if (pos[a].s < miny) miny = pos[a].s;
			if (pos[a].s > maxy) maxy = pos[a].s;
		}

		minp = min(minp, ((maxy - miny) << 1) + ((maxx - minx) << 1));
	}
	
	cout << minp << endl;
}