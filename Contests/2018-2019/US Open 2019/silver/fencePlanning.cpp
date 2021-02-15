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

int x[100001], y[100001];

int perimeter(int x1, int y1, int x2, int y2) {
	return ((y2 - y1) + (x2 - x1)) << 1;
}

int calc(vi v) {
	int minX = __INT_MAX__, maxX = 0;
	int minY = __INT_MAX__, maxY = 0;

	for (auto a : v) {
		minX = min(minX, x[a]);
		maxX = max(maxX, x[a]);
		minY = min(minY, y[a]);
		maxY = max(maxY, y[a]);
	}

	return perimeter(minX, minY, maxX, maxY);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("fenceplan");	

	int n, m;
	cin >> n >> m;

	ff0r(i, n){
		cin >> x[i] >> y[i];
	}

	DSU d;
	d.init(n);

	ff0r(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		d.unite(a, b);
	}

	map<int, vi> ma;

	ff0r(i, n) {
		ma[d.get(i)].pb(i);		
	}

	int area = __INT_MAX__;
	for (auto a : ma) {
		area = min(calc(a.s), area);
	}

	cout << area << endl;
}