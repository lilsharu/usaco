#include <bits/stdc++.h>
using namespace std;

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

bool vis[101][101]; // X vs Y

struct val{
	int k, x, y;	
	val() {}
	val(int ka, int xa, int ya) : k(ka), x(xa), y(ya) {};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("pails.in", "r", stdin);

	int x, y, k, m;
	cin >> x >> y >> k >> m;

	queue<val> q;
	q.push(val(0, 0, 0));

	int mg = m;

	while (!q.empty()) {
		val cur = q.front();
		q.pop();
		if (cur.k > k || vis[cur.x][cur.y]) continue;
		vis[cur.x][cur.y] = true;

		mg = min(mg, abs(m - cur.x - cur.y));

		// Fill X
		q.push(val(cur.k + 1, x, cur.y));

		// Fill Y
		q.push(val(cur.k + 1, cur.x, y));

		// Empty X
		q.push(val(cur.k + 1, 0, cur.y));

		// Empty Y
		q.push(val(cur.k + 1, cur.x, 0));

		// Empty X into Y
		int mvmt = min(y - cur.y, cur.x);
		q.push(val(cur.k + 1, cur.x - mvmt, cur.y + mvmt));

		// Empty Y into X
		mvmt = min(x - cur.x, cur.y);
		q.push(val(cur.k + 1, cur.x + mvmt, cur.y - mvmt));
	}

	cout << mg << endl;
}