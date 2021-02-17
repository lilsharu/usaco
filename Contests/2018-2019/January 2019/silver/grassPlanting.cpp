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

vi adj[100001];
bool visited[100001];
vi ta;

bool cmp(int& a, int& b) {
	return adj[a].size() > adj[b].size();
}

void updateQ(int& parent, queue<int>& q) {
	for (auto a : adj[parent]) {
		if (!visited[a]) ta.pb(a);
	}	

	sort(all(ta), cmp);

	for (auto a : ta) {
		q.push(a);
	}

	ta.clear();
}

void updateQ(vi& p, queue<int>& q) {
	for (auto parent : p) {
		for (auto a : adj[parent]) {
			if (!visited[a]) ta.pb(a);
		}
	}

	sort(all(ta), cmp);

	for (auto a : ta) {
		q.push(a);
	}

	ta.clear();
}

// 9 / 10
// Strategy: BFS
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("planting");

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	int root = 0;

	for (int i = 0; i < n; i++) {
		if (adj[i].size() > adj[root].size()) root = i;
	}

	int total = 1 + adj[root].size();
	visited[root] = true;

	queue<int> q;
	updateQ(root, q);

	vi np;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int next = q.front();
			visited[next] = true;
			q.pop();

			int av = total - 2;
			int count = 0;

			for (auto a : adj[next]) {
				if (!visited[a]) count++;
			}

			if (av < count) {
				total += count - av;
			}
			np.pb(next);
		}
		updateQ(np, q);
	}

	cout << total << endl;
}