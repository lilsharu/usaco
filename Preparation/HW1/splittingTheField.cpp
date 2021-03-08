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

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

ll calc(ll a, ll b, ll c, ll d) {
	return abs((c - a) * (d - b));
}

map<ll, pll> m;

// Need to check vertically as well
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("split");

	int n; cin >> n;

	ll minx = 1e9 + 1, miny = 1e9 + 1, maxx = 0, maxy = 0;
	vll xv(n);
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
		xv[i] = x;

		if (!(m.count(x))) {
			m[x] = {y, y};
		} else {
			m[x].f = min(m[x].f, y);
			m[x].s = max(m[x].s, y);
		}
	}
	sort(all(xv));

	auto lst = unique(all(xv));
	xv.erase(lst, xv.end());

	ll totBefore = calc(minx, miny, maxx, maxy);
	
	n = xv.size();

	vll pmin(n), smin(n), pmax(n), smax(n);
	pmin[0] = m[xv[0]].f;
	pmax[0] = m[xv[0]].s;
	for (int i = 1; i < n; i++) {
		pmin[i] = min(pmin[i - 1], m[xv[i]].f);
		pmax[i] = max(pmax[i - 1], m[xv[i]].s);
	}
	
	smin[n - 1] = m[xv[n - 1]].f;
	smax[n - 1] = m[xv[n - 1]].s;
	for (int i = n - 2; i >= 0; i--) {
		smin[i] = min(smin[i + 1], m[xv[i]].f);
		smax[i] = max(smax[i + 1], m[xv[i]].s);
	}

	ll tot = totBefore;
	for (int i = 0; i < n; i++) {
		ll val = 0;
		{
			ll minx = xv[0];
			ll maxx = xv[i];
			ll miny = pmin[i];
			ll maxy = pmax[i];

			val += calc(minx, miny, maxx, maxy);
		}
		{
			ll minx = xv[i + 1];
			ll maxx = xv[n - 1];
			ll miny = smin[i + 1];
			ll maxy = smax[i + 1];

			val += calc(minx, miny, maxx, maxy);
		}
		tot = min(tot, val);
	}

	cout << totBefore - tot << endl;
}