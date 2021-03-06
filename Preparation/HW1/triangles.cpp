#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long ll;
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

const ll shift = 20001; //10001;

vll y[10001 + shift];
vll x[10001 + shift];
vll ysum[10001 + shift];
vll xsum[10001 + shift];
vpl pairs;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("triangles");

	ll n;
	cin >> n;
	pairs.resize(n);

	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a += shift, b += shift;

		pairs[i] = {a, b};
	
		x[b].pb(a);
		y[a].pb(b);
	}

	for (ll i = 0; i < 10001 + shift; i++) {
		sort(all(y[i]));
		sort(all(x[i]));
	}

	for (ll i = 0; i < 10001 + shift; i++) {
		// Find Y Sums first
		{
			ll total = 0;
			for (ll j = 1; j < y[i].size(); j++) {
				total += y[i][j] - y[i][0];
			}

			ysum[i].pb(total);

			for (ll j = 1; j < y[i].size(); j++) {
				ll dist = y[i][j] - y[i][j - 1];
				total = total + j * dist - (y[i].size() - j) * dist;
				ysum[i].pb(total);
			}
		}
		{
			ll total = 0;
			for (ll j = 1; j < x[i].size(); j++) {
				total += x[i][j] - x[i][0];
			}

			xsum[i].pb(total);

			for (ll j  = 1; j < x[i].size(); j++) {
				ll dist = x[i][j] - x[i][j - 1];
				total = total + j * dist - (x[i].size() - j) * dist;
				xsum[i].pb(total);
			}
		}
	}

	unsigned long long tot = 0;
	for (auto a : pairs) {
		ll xind = lower_bound(all(y[a.s]), a.f) - y[a.s].begin();
		ll yind = lower_bound(all(x[a.f]), a.s) - x[a.f].begin();

		tot += xsum[a.s][xind] * ysum[a.f][yind];
		tot %= 1000000007;
	}

	cout << tot << endl;
}