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

bool work(ll n, ll k, ll m, ll x) {
	ll t = 0;
	ll g = 0;

	while (g < n && k) {
		ll y = (n - g) / x;
		// Check if we need to use m
		if (y <= m) {
			t += (n - g + m - 1) / m;
			return t <= k;
		}

		ll gmax = n - x * y;
		ll time = (gmax - g) / y + 1;
		g += y * time;
		t += time;
	}

	return t <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("loan");

	ll n, k, m;

	cin >> n >> k >> m;

	ll x = 1;
	for (int jump = 1e9; jump >= 1; jump >>= 1) {
		while (work(n, k, m, x + jump)) x += jump;
	}

	cout << x << endl;
}