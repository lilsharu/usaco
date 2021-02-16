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

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

bool grid[1000][1000];

int num(int i1, int j1, int i2, int j2, int b) {
	int total = 0;
	for (int i = i1; i <= i2; i++) {
		for (int j = j1; j <= j2; j++) {
			if (grid[i][j] == b) total++;
		}
	}

	return total;
}

// 10 / 12
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("leftout");
	int n;
	cin >> n;

	string s;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = s[j] == 'L';
		}
	}

	// Flip columns and rows so top row and left column are zero
	for (int i = 1; i < n; i++) {
		grid[i][0] = grid[i][0] ^ grid[0][0];
		for (int j = 1; j < n; j++) grid[i][j] = grid[i][j] ^ grid[0][j] ^ grid[i][0];
	}

	if (num(1, 1, n - 1, n - 1, 0) == 0) { 
		cout << "1 1\n";
		return 0;
	}

	if (num(1, 1, n - 1, n - 1, 0) == n - 1) {
		for (int j = 1; j < n; j++) {
			if (num(1, j, n - 1, j, 1) == n - 1) {
				cout << 1 << ' ' << j + 1 << endl;
				return 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (num(i, 1, i, n - 1, 1) == n - 1) {
				cout << i + 1 << ' ' << 1 << endl;
				return 0;
			}
		}
	}

	if (num(1, 1, n - 1, n - 1, 1) != 1) {
		cout << -1 << endl;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == 1) {
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
		}
	}
}
