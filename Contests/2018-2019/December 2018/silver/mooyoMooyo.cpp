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

#define pos(i, j) 10 * i + j

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int n, k;
int c[101][10];
bool visited[1001];

int area;

void search(int i, int j, int r) {
	if (j >= 10 || j < 0 || i >= n || i < 0) return;
	if (!visited[pos(i, j)] && c[i][j] == r) {
		visited[pos(i, j)] = 1;
		area++;
		search(i + 1, j, r);
		search(i - 1, j, r);
		search(i, j - 1, r);
		search(i, j + 1, r);
	}
}

void fill(int i, int j, int r) {
	if (j >= 10 || j < 0 || i >= n || i < 0) return;
	if (c[i][j] == r) {
		c[i][j] = 0;
		fill(i + 1, j, r);
		fill(i - 1, j, r);
		fill(i, j - 1, r);
		fill(i, j + 1, r);
	}
}

void gravity() {
	for (int j = 0; j < 10; j++) {
		vi pos;
		for (int i = n - 1; i >= 0; i--) {
			if (c[i][j]) pos.pb(i);
		}
		int x = 0;
		for (int i = n - 1; i >= 0; i--) {
			c[i][j] = (x < pos.size() ? c[pos[x++]][j] : 0);
		}
	}
}

vpi roots;
int find() {
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (!visited[pos(i, j)] && c[i][j]) {
				search(i, j, c[i][j]);
				if (area >= k) {
					fill(i, j, c[i][j]);
					roots.pb({i, j});
					total++;
				}
				area = 0;
			}
		}
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("mooyomooyo");

	cin >> n >> k;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 10; j++) {
			c[i][j] = s[j] - '0';
		}
	}

	while (find()) {
		gravity();
		roots.clear();
		memset(visited, 0, 1001);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}

	return 0;
}