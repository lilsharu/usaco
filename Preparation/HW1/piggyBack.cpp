#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
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

ll b, e, p, n, m;

vll adj[40001];
ll barn[40001];
ll bess[40001];
ll els[40001];

void bessieBfs(ll val) {
	queue<ll> q;	
	// Find distance from Bessie
	q.push(val);
	bess[val] = 0;
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll next : adj[v]) {
			if (bess[next] > bess[v] + 1) {
				bess[next] = bess[v] + 1;
				q.push(next);
			}
		}
	}
}

void elsBfs(ll val) {
	queue<ll> q;	
	// Find distance from Bessie
	q.push(val);
	els[val] = 0;
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll next : adj[v]) {
			if (els[next] > els[v] + 1) {
				els[next] = els[v] + 1;
				q.push(next);
			}
		}
	}
}

void barnBfs(ll val) {
	queue<ll> q;	
	// Find distance from Bessie
	q.push(val);
	barn[val] = 0;
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll next : adj[v]) {
			if (barn[next] > barn[v] + 1) {
				barn[next] = barn[v] + 1;
				q.push(next);
			}
		}
	}
}

// 6 / 11
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("piggyback");

	cin >> b >> e >> p >> n >> m;

	for (int i = 0; i < m; i++) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for (int i = 0; i < 40001; i++) {
		barn[i] = 1 << 30;
		els[i] = 1 << 30;
		bess[i] = 1 << 30;
	}

	// Find distance from Bessie
	bessieBfs(0);

	// Find distances from Elsie
	elsBfs(1);

	if (b + e < p) {
		cout << b * bess[n - 1] + e * els[n - 1] << endl;
		return 0;
	}

	
	// find distance from the barn (at n - 1)
	barnBfs(n - 1);

	ll tot = b * bess[n - 1] + e * els[n - 1];
	for (int i = 0; i < n; i++) {
		if (bess[i] == -1 || els[i] == -1 || barn[i] == -1) continue;
		ll d = b * bess[i] + e * els[i] + p * barn[i];
		tot = min(tot, d);
	}

	cout << tot << endl;
	return 0;
}