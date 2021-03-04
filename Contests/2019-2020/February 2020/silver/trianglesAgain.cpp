#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n'
#define f first
#define s second

#define MOD (int) 1e9 + 7

const int off = 10000;
vi hor[20005];
vi ver[20005];
vi hsum[20005];
vi vsum[20005];

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("triangles");

	int n; cin >> n;
	vpi arr(n);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x; cin >> y;
		x += off, y += off;
		arr[i].f = x, arr[i].s = y;
		hor[y].pb(x);
		ver[x].pb(y);
	}

	for (int i = 0; i < 10001 + off; i++) {
		sort(all(hor[i]));
		sort(all(ver[i]));
	}

	// psum for horizontal
	for (int i = 0; i < 10001 + off; i++) {
		if (hor[i].size()) {
			int sum = 0;
			int fe = hor[i][0];
			// find prefix sum from the first point
			for (int j = 1; j < hor[i].size(); j++) {
				sum += hor[i][j] - fe;
			}

			hsum[i].pb(sum);
			// apply trnaslation to the later points
			for (int j = 1; j < hor[i].size(); j++) {
				int dist = hor[i][j] - hor[i][j - 1];
				sum += j * dist;
				sum -= (hor[i].size() - j) * dist;
				hsum[i].pb(sum);
			}
		}
	}

	// psum for vertical
	for (int i = 0; i < 10001 + off; i++) {
		if (ver[i].size()) {
			int sum = 0;
			int fe = ver[i][0];
			// find prefix sum from the first point
			for (int j = 1; j < ver[i].size(); j++) {
				sum += ver[i][j] - fe;
			}

			vsum[i].pb(sum);
			// apply trnaslation to the later points
			for (int j = 1; j < ver[i].size(); j++) {
				int dist = ver[i][j] - ver[i][j - 1];
				sum += j * dist;
				sum -= (ver[i].size() - j) * dist;
				vsum[i].pb(sum);
			}
		}
	}

	long total = 0;
	// go through each point, find hsum and vsum, and multiply and add to total
	for (int i = 0; i < n; i++) {
		int x = arr[i].f;
		int y = arr[i].s;

		// figure out where x is located (index)
		int indexH = lower_bound(all(hor[y]), x) - hor[y].begin();
		ll sumH = hsum[y][indexH];

		// figure out where x is for y (index)
		int indexV = lower_bound(all(ver[x]), y) - ver[x].begin();
		ll sumV = vsum[x][indexV];

		total += sumH * sumV;
		total %= MOD;
	}

	cout << total << endl;	
}