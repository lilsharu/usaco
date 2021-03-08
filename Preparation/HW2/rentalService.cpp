#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	setIO("rental");

	int n, m, r;
	cin >> n >> m >> r;

	vll milkPotential(n);
	vpl milkSell(m);
	vll cowRent(r);
	for (int i = 0; i < n; i++) cin >> milkPotential[i];
	for (int i = 0; i < m; i++) cin >> milkSell[i].s >> milkSell[i].f;
	for (int i = 0; i < r; i++) cin >> cowRent[i];

	sort(all(milkPotential), [](ll& a, ll& b) -> bool {return a > b;});
	sort(all(milkSell),      [](pll& a, pll& b) -> bool {return (a.f == b.f) ? a.s > b.s : a.f > b.f;});
	sort(all(cowRent),       [](ll& a, ll& b) -> bool {return a > b;});

	vll sellEarn(n + 1);
	vll rentEarn(n + 1);

	int cm = 0;
	for (int i = 1; i <= n; i++) {
		int c = milkPotential[i - 1];
		sellEarn[i] = sellEarn[i - 1];
		while (cm < m && milkSell[cm].s < c) {
			c -= milkSell[cm].s;
			sellEarn[i] += milkSell[cm].s * milkSell[cm].f;
			milkSell[cm].s = 0;
			cm++;
		}
		if (cm < m && milkSell[cm].s >= c) {
			milkSell[cm].s -= c;
			sellEarn[i] += c * milkSell[cm].f;
		}
	}

	for (int i = 1; i <= n; i++) {
		rentEarn[i] = rentEarn[i - 1] + (i <= r ? cowRent[i - 1] : 0);
	}

	ll tot = 0;
	for (int i = 0; i <= n; i++) {
		tot = max(tot, sellEarn[i] + rentEarn[n - i]);
	}

	cout << tot << endl;
}