#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpl;

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

// try to sell all of your cows
// sel the worst cows for the highest prices
// then try to figure out how much you would make by milking the top i cows

// sell[i] = profit from selling the worst cows
// milk[i] = profit from milking the best i cows
// so our answer is for all i..N-1 max(milk[i] + sell[N - i - 1])

ll n, m, r;
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
}