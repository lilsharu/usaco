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

#define sqr(a) ((ll) a) * (a)

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

struct pos {
	ll j, b, c;
	pos(ll jj, ll bb, ll cc) : b(bb), j(jj), c(cc) {}
	pos() : b(0), j(0), c(0) {}
};

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("radio");

	cin >> n >> m;

	ll dist[n + 1][m + 1];
	ll curc[n + 1][m + 1];

	int jsx, jsy, bsx, bsy;
	cin >> jsx >> jsy >> bsx >> bsy;

	vi jx(n + 1);	
	vi jy(n + 1);
	vi bx(m + 1);
	vi by(m + 1);

	string john; cin >> john;
	string bessie; cin >> bessie;

	jx[0] = jsx;
	jy[0] = jsy;
	bx[0] = bsx;
	by[0] = bsy;

	for (int i = 1; i <= n; i++) {
		char c = john[i - 1];
		jy[i] = jy[i - 1];
		jx[i] = jx[i - 1];
		switch (c) {
			case 'N': {
				jy[i]++;
				break;
			}
			case 'S': {
				jy[i]--;
				break;
			}
			case 'E': {
				jx[i]++;
				break;
			}
			default: {
				jx[i]--;
				break;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		char c = bessie[i - 1];
		by[i] = by[i - 1];
		bx[i] = bx[i - 1];
		switch (c) {
			case 'N': {
				by[i]++;
				break;
			}
			case 'S': {
				by[i]--;
				break;
			}
			case 'E': {
				bx[i]++;
				break;
			}
			default: {
				bx[i]--;
				break;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dist[i][j] = sqr(bx[j] - jx[i]) + sqr(by[j] - jy[i]);
			curc[i][j] = __LONG_LONG_MAX__;
		}
	}

	ll minc = __LONG_LONG_MAX__;
	queue<pos> q;
	q.push(pos(0, 0, 0));

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (curc[cur.j][cur.b] < cur.c) {
			continue;
		}
		if (cur.b > m || cur.j > n) {
			continue;
		}
		if (cur.b == m && cur.j == n) {
			minc = min(minc, cur.c);
			continue;
		}

		if (cur.b + 1 <= m && curc[cur.j][cur.b + 1] > cur.c + dist[cur.j][cur.b + 1]) {
			q.push(pos(cur.j, cur.b + 1, cur.c + dist[cur.j][cur.b + 1]));
			curc[cur.j][cur.b + 1] = cur.c + dist[cur.j][cur.b + 1];
		}
		if (cur.j + 1 <= n && curc[cur.j + 1][cur.b] > cur.c + dist[cur.j + 1][cur.b]) {
			q.push(pos(cur.j + 1, cur.b, cur.c + dist[cur.j + 1][cur.b]));
			curc[cur.j + 1][cur.b] = cur.c + dist[cur.j + 1][cur.b];
		}
		if (cur.b + 1 <= m && cur.j + 1 <= n && curc[cur.j + 1][cur.b + 1] > cur.c + dist[cur.j + 1][cur.b + 1]) {
			q.push(pos(cur.j + 1, cur.b + 1, cur.c + dist[cur.j + 1][cur.b + 1]));
			curc[cur.j + 1][cur.b + 1] = cur.c + dist[cur.j + 1][cur.b + 1];
		}
	}

	cout << minc << endl;
}