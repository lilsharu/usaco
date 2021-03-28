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

struct el {
	ll t, r, x, y;
	string s;
	el(ll tt, ll rr, ll xx, ll yy) : t(tt), r(rr), x(xx), y(yy), s("") {}
	el(ll tt, ll rr, ll xx, ll yy, string ss) : t(tt), r(rr), x(xx), y(yy), s(ss) {}
	el() : t(0), r(0), x(0), y(0), s("") {}
};

ll field[101][101];
ll vis[3][101][101];

// 3 TLE
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	setIO("visitfj");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				vis[i][j][k] = LONG_LONG_MAX;
			}
		}
	}

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}

	ll res = LONG_LONG_MAX;
	queue<el> q;
	q.push(el(0, 0, 0, 0));

	while (!q.empty()) {
		el c = q.front();
		q.pop();
		
		c.t += c.r % 3 || c.r == 0 ? 0 : field[c.x][c.y];
		if (vis[c.r % 3][c.x][c.y] <= c.t || c.t >= res) continue;
		if (c.x + 1 == n && c.y + 1 == n) {
			res = min(res, c.t);
			continue;
		}
		vis[c.r % 3][c.x][c.y] = c.t;
		if (c.x + 1 < n) q.push(el(c.t + t, c.r + 1, c.x + 1, c.y));
		if (c.y + 1 < n) q.push(el(c.t + t, c.r + 1, c.x, c.y + 1));
		if (c.x - 1 >= 0) q.push(el(c.t + t, c.r + 1, c.x - 1, c.y));
		if (c.y - 1 >= 0) q.push(el(c.t + t, c.r + 1, c.x, c.y - 1));
	}

	cout << res << endl;
}