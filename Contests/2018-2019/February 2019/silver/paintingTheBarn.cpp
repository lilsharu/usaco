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

int psum[1002][1002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("paintbarn");

	int n, k;
	cin >> n >> k;
	
	if (k > n) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a++, b++, c++, d++;

		psum[a][b]++;
		psum[c][d]++;
		psum[a][d]--;
		psum[c][b]--;
	}

	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			int newval = psum[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
			psum[i][j] = newval;
		}
	}

	int total = 0;
	for (int i = 1; i < 1002; i++) {
		for (int j = 1; j < 1002; j++) {
			if (psum[i][j] == k) total++;
		}
	}
	
	cout << total << endl;
	return 0;
}