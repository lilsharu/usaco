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

#define pos(i, j) 250 * i + j

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int c[251][251];
bool v[251][251];
bool v2[250 * 250 + 1];
int trans[1000001];
int n;

int tot = 0;
void unisearch(int i, int j, int r, unordered_set<int>& opt) {
	if (v[i][j] || i < 0 || i >= n || j < 0 || j >= n) return;
	else if (c[i][j] != r) {
		opt.insert(c[i][j]);	
		return;
	}
	v[i][j] = true;
	tot++;	
	unisearch(i + 1, j, r, opt);
	unisearch(i - 1, j, r, opt);
	unisearch(i, j + 1, r, opt);
	unisearch(i, j - 1, r, opt);
}

void multisearch(int i, int j, int r1, int r2) {
	if (v2[pos(i, j)] || !(c[i][j] == r1 || c[i][j] == r2) || i < 0 || i >= n || j < 0 || j >= n) return;
	v2[pos(i, j)] = true;
	tot++;
	multisearch(i + 1, j, r1, r2);
	multisearch(i - 1, j, r1, r2);
	multisearch(i, j + 1, r1, r2);
	multisearch(i, j - 1, r1, r2);
}

// 9 / 10 (TLE)
// Strategy: Floodfill
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("multimoo");

	cin >> n;

	int next = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			c[i][j] = (trans[x] ? trans[x] : trans[x] = next++);	
		}
	}

	int mi = 0, mm = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j]) {
				unordered_set<int> opt;
				unisearch(i, j, c[i][j], opt);
				mi = max(mi, tot);
				tot = 0;
				for (auto a : opt) {
					memset(v2, 0, 250 * 250 + 1);
					multisearch(i, j, c[i][j], a);	
					mm = max(mm, tot);
					tot = 0;
				}
			}
		}
	}

	cout << mi << endl << mm << endl;
}