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

struct seg {
	pii p; 
	bool left;
	int index;
};
bool operator < (const seg &a, const seg &b) {
	return a.p < b.p;
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

int n;
seg p[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("cowjump");

	cin >> n;

	for (int i = 0; i < (n << 1); i += 2) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p[i].index = i;
		p[i].p = {a, b};
		p[i].left = true;

		p[i + 1].index = i;
		p[i + 1].p = {c, d};
		p[i + 1].left = false;
	}

	sort(p, p + (n << 1));
}