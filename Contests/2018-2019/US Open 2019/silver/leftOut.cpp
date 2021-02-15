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

bool v[1000][1000];
int psum[1001][1001];

// int rangeQuery(int x1, int y1, int x2, int y2, bool tf) {
// 	int total = 0;
// 	ffor(i, x1, x2 + 1) {
// 		ffor(j, y1, y2 + 1) {
// 			if (v[i][j] == tf) total++;
// 		}
// 	}
// 	return total;
// }

int sum(int x1, int y1, int x2, int y2) {
	return psum[x2 + 1][y2 + 1] - psum[x1][y1];
}

// 4 / 12
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("leftout");
	int n;
	cin >> n;
	
	fforn {
		string s;
		cin >> s;
		ff0r(j, n) {
			v[i][j] = s[j] == 'R';
		}
	}

	// Flip Top Row
	for (int i = 1; i < n; i++) {
		if (v[i][0]) {
			for (int j = 0; j < n; j++) {
				v[i][j] = !v[i][j];
			}
		}
	}

	// Flip Left Column
	for (int i = 1; i < n; i++) {
		if (v[0][i]) {
			for (int j = 0; j < n; j++) {
				v[j][i] = !v[j][i];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			psum[i][j] = v[i - 1][j - 1] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
		}
	}

	if (sum(0, 0, n - 1, n - 1) == 0) { 
		cout << -1 << endl; return 0;
	}

	if (sum(1, 1, n - 1, n - 1) == 0) {
		cout << 1 << ' ' << 1 << endl; return 0;
	}

	if (sum(1, 1, n - 1, n - 1) == n - 1) {
		for (int i = 0; i < n; i++) {
			if (sum(i, 0, i, n - 1) == n - 1) {
				cout << i + 1 << ' ' << '0' << endl;
				return 0;
			}
			if (sum(0, i, n - 1, i) == n - 1) {
				cout << 0 << ' ' << i + 1 << endl;
			}
		}
	}

	if (sum(1, 1, n - 1, n - 1) != 1) {
		cout << -1 << endl;
		return 0;
	}
	
	if (sum(1, 1, n - 1, n - 1) == 1) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (v[i][j]) {
					cout << i + 1 << ' ' << j + 1 << endl;
					return 0;
				}
			}
		}
	}


//   // Flip columns and rows so top row and left column all zero
// 	for (int i=1; i<n; i++) {
// 		v[i][0] = v[i][0] ^ v[0][0];
// 		for (int j=1; j<n; j++) v[i][j] = v[i][j] ^ v[0][j] ^ v[i][0];
// 	}

	// if (rangeQuery(1, 1, n - 1, n - 1, 0) == 0) { cout << "1 1\n";
	// 	return 0;
	// }

	// if (rangeQuery(1, 1, n - 1, n - 1, 1) == n - 1) {
	// 	ffor(j, 1, n) {
	// 		if (rangeQuery(1, j, n - 1, j, 1) == n - 1) {
	// 			cout << 1 << ' ' << j + 1 << endl;
	// 			return 0;
	// 		}
	// 	}
	// 	ffor(j, 1, n) {
	// 		if (rangeQuery(j, 1, j, n - 1, 1) == n - 1) {
	// 			cout << j + 1 << ' ' << 1 << endl;
	// 			return 0;
	// 		}
	// 	}
	// 	cout << -1 << endl;
	// 	return 0;
	// }

	// if (rangeQuery(1, 1, n - 1, n - 1, 1) != 1) {
	// 	cout << -1 << endl;
	// 	return -1;
	// }

	// ff0r(i, n) {
	// 	ff0r(j, n) {
	// 		if (v[i][j]) {
	// 			cout << i << ' ' << j << endl;
	// 			return 0;
	// 		}
	// 	}
	// }

}