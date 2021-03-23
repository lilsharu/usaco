#include <bits/stdc++.h>

using namespace std;
struct DSU {
	vector<int> e;

	void init(int n) {
	e = vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool sameSet(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

vector<pair<int, int>> sol;
DSU d;
int tot = 0;

void combine(int a, int b) {
	if (a == b || d.sameSet(a, b)) return;
	tot++;
	sol.push_back({a, b});
	d.unite(a, b);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;
	d.init(26);

	// Check each index for comparison
	for (int i = 0; i < n; i++) {
		int c = a[i] - 'a', d = b[i] - 'a';
		combine(c, d);
	}

	cout << tot << endl;

	for (auto p : sol) {
		cout << (char)(p.first + 'a') << ' ' << (char)(p.second + 'a') << endl;
	}
	
	return 0;
}
