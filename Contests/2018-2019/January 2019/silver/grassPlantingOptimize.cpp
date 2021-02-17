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
int layer[100001], numLayers = 0;
int order[100001];

void layerize(int x, int l) {
	layer[x] = l;
	visited[x] = true;
	for (auto a : adj[x]) {
		if (!visited[a]) layerize(a, l + 1);
	}
	numLayers = max(numLayers, l + 1);
}

bool csize(int& a, int& b) {
	return (layer[a] == layer[b]) ? adj[a].size() > adj[b].size() : layer[a] < layer[b];
}

// 10 / 10
// Strategy: Ad Hoc?
// Bascially, based on an initially BFS Solution with a large degree of 
// optimization and full removal of BFS

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

	layerize(root, 0);
	iota(order, order + n, 0);
	sort(order, order + n, csize);

	for (int i = 1; i < n; i++) {
		int count = adj[i].size() - 1;
		if (count > total - 2) {
			total += count + 2 - total;
		}
		while (i + 1 < n && layer[i + 1] == layer[i]) i++;
	}

	cout << total << endl;
}