#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;

#define all(x) begin(x), end(x)

#define f first
#define s second

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int n, m;
vpl v;

bool test(ll gap) {
	ll start = v[0].f;
	int num = n - 1;
	ll ind = 0;
	while (ind < m && num) {
		while (ind < m && v[ind].s < start + gap) ind++;
		if (ind == m) break;
		start = max(start + gap, v[ind].f);
		num--;
	}

	return num <= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("socdist");

	cin >> n >> m;
	v.resize(m);

	for (int i = 0; i < m; i++) cin >> v[i].f >> v[i].s;

	sort(all(v));

	ll gap = 1;
	for (ll jump = 1e9; jump >= 1; jump >>= 1) {
		while (test(gap + jump)) gap += jump;
	}

	cout << gap << endl;
}