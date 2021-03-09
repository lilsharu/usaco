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

#define endl '\n'
#define f first
#define s second

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

vi adj[100001];
vi dist;
vector<bool> vis;

int parent(int& a) {
	for (int next : adj[a]) {
		if (dist[next] < dist[a]) return next;
	}
	return a;
};

void clear(int& root) {
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto next : adj[cur]) {
			if (!vis[next] && dist[next] > dist[cur]) {
				vis[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("atlarge");

	int n, k;
	cin >> n >> k;
	k--;

	vi exits;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	queue<int> q;
	dist.resize(n, 1 << 30);
	q.push(k);
	dist[k] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (adj[cur].size() == 1) exits.pb(cur);
		else {
			for (auto next : adj[cur]) {
				if (dist[cur] + 1 < dist[next]) {
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	// sort exits by distance from bessie
	sort(all(exits), [](int& a, int& b) {
		return dist[a] < dist[b];
	});

	vis.resize(n);
	int tot = 0;
	for (auto cur : exits) {
		if (vis[cur]) continue;
		int move = dist[cur] >> 1;
		int root = cur;
		while (move--) {
			root = parent(root);
		}
		tot++;
		clear(root);		
	}

	cout << tot << endl;
}