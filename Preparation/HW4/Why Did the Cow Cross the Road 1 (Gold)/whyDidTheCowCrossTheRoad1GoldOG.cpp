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
	el(ll tt, ll rr, ll xx, ll yy) : t(tt), r(rr), x(xx), y(yy) {}
	el() : t(0), r(0), x(0), y(0) {}
};

int field[101][101];
int vis[3][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	setIO("visitfj");

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}

	queue<el> q;
	q.push(el(0, 0, 0, 0));

	ll curMin = LONG_LONG_MAX;
	
	while (!q.empty()) {
		el c = q.front();
		q.pop();

		// if (c.x > n || c.x < 0 || c.y > n || c.y < 0 || t > curMin) continue;
		if (c.x == n && c.y == n) {
			curMin = min(curMin, c.t + t + (c.r % 3 == 0 ? field[c.x][c.y] : 0));
			continue;
		}

		int addT = t + (c.r != 0 && c.r % 3 == 0 ? field[c.x][c.y] : 0);
		
		if (vis[c.r % 3][c.x][c.y] != 0 && vis[c.r % 3][c.x][c.y] <= c.t + addT) {
			continue;
		}

		vis[c.r % 3][c.x][c.y] = c.t + addT;

		if (!(c.x + 1 > n || c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x + 1][c.y] : 0) > curMin || (vis[(c.r + 1) % 3][c.x + 1][c.y] != 0 && vis[(c.r + 1) % 3][c.x + 1][c.y] <= c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x + 1][c.y] : 0))))
			q.push(el(c.t + addT, c.r + 1, c.x + 1, c.y));

		if (!(c.y + 1 > n || c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x][c.y + 1] : 0) > curMin || (vis[(c.r + 1) % 3][c.x][c.y + 1] != 0 && vis[(c.r + 1) % 3][c.x][c.y + 1] <= c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x][c.y + 1] : 0))))
			q.push(el(c.t + addT, c.r + 1, c.x, c.y + 1));

		if (!(c.x - 1 < 0 || c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x - 1][c.y] : 0) > curMin || (vis[(c.r + 1) % 3][c.x - 1][c.y] != 0 && vis[(c.r + 1) % 3][c.x - 1][c.y] <= c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x - 1][c.y] : 0))))
			q.push(el(c.t + addT, c.r + 1, c.x - 1, c.y));

		if (!(c.y - 1 < 0 || c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x][c.y - 1] : 0) > curMin || (vis[(c.r + 1) % 3][c.x][c.y - 1] != 0 && vis[(c.r + 1) % 3][c.x][c.y - 1] <= c.t + addT + ((c.r + 1) % 3 == 0 ? field[c.x][c.y - 1] : 0))))
			q.push(el(c.t + addT, c.r + 1, c.x, c.y - 1));
	}

	cout << curMin << endl;
	// cout << 31 << endl;
}