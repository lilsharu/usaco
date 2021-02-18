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

int n;
bool b[1002][1002], visited[1002][1002];

int p[1002];
int a[1002];

vector<set<int>> groups;
int group = 0;

void search(int i, int j) {
	if (!b[i][j]) {
		p[group]++;
		return;
	} else if (visited[i][j]) return;
	visited[i][j] = true;
	a[group]++;
	search(i, j + 1);
	search(i, j - 1);
	search(i + 1, j);
	search(i - 1, j);
}

// 10 / 11
// Strategy: Floodfill
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("perimeter");

	cin >> n;

	string s;
	for (int i = 1; i < n + 1; i++) {
		cin >> s;
		b[i][0] = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == '#') b[i][j + 1] = 1;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (b[i][j] && !visited[i][j]) {
				search(i, j);
				group++;
			}
		}
	}

	int ind = 0;
	int amax = a[0];
	int ip = p[0];

	for (int i = 1; i < group; i++) {
		if (a[i] > amax) {
			amax = a[i];
			ip = p[i];
			ind = i;
		} else if (a[i] == amax) {
			if (p[i] < ip) {
				ip = p[i];
				ind = i;
			}
		}
	}

	cout << amax << ' ' << ip << endl;
	return 0;
}