#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

#define pb push_back
#define all(x) begin(x), end(x)

#define ffor(i,a,b) for (ll i = (a); i < (b); ++i)
#define ff0r(i,a) ffor(i,0,a)
#define rrof(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define rr0f(i,a) rrof(i,0,a)
#define trav(a,x) for (auto& a: x)
#define fforn ff0r(i, n)

#define read(a) ll (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

ll n, m, r;

bool cmp(pll& a, pll& b) {
	return (a.f == b.f) ? a.s > b.s : a.f > b.f;
}

bool cmpll(ll& a, ll& b) {
	return a > b;
}

// Correct: 3
// Incorrect: 7
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("rental");

	ll cm = 0, cr = 0;
	vll v, rent;
	vpl milk;


	cin >> n >> m >> r;

	v.resize(n);
	milk.resize(m);
	rent.resize(r);

	for (ll i = 0; i < n; i++) cin >> v[i];

	for (ll i = 0; i < m; i++) {
		cin >> milk[i].s >> milk[i].f;
	}

	for (ll i = 0; i < r; i++) {
		cin >> rent[i];
	}

	sort(all(v), cmpll);
	sort(all(rent), cmpll);
	sort(all(milk), cmp);

	vpl mmilk = milk;

	ll tot = 0;
	ll i = 0;
	auto vv = v;
	for (i = 0; i < n && cm < m; i++) {
		auto c = vv[i];
		while (mmilk[cm].s < c && cm < m) {
			c -= mmilk[cm].s;
			tot += (mmilk[cm].s * mmilk[cm].f);
			mmilk[cm].s = 0;
			cm++;
		}
		if (cm < m) {
			mmilk[cm].s -= c;
			tot += c * mmilk[cm].f;
			vv[i] = 0;
		}
	}

	if (cm == m) cm--;

	ll mi = i;
	for (i = n - 1; i >= mi && cr < r; i++, cr++) {	
		tot += rent[cr];
	}

	if (cr == r) {
		cout << tot << endl;
		return 0;
	}

	while ((v[i] - vv[i]) * mmilk[cm].f < rent[cr] && i >= 0 && cm >= 0 && cr < r) {
		tot += rent[cr++];// - (v[i] - vv[i]) * mmilk[cm].f;
		while (mmilk[cm].s + v[i] - vv[i] > milk[cm].s) {
			tot -= mmilk[cm].f * (milk[cm].s - mmilk[cm].s);
			vv[i] += milk[cm].s - mmilk[cm].s;
			mmilk[cm].s = milk[cm].s;
			cm--;
		}
		if (i >= 0) {
			tot -= mmilk[cm].f * (v[i] - vv[i]);
			mmilk[cm].s += (v[i] - vv[i]);
			i--;
		}
	}

	cout << tot << endl;
}