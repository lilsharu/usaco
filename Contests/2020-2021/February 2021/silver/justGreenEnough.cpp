#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int inc[501][502]; // Includes 100
int exc[501][502]; // Excludes 100

ll tot = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			inc[i][j] = x < 100;
			exc[i][j] = x <= 100;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			inc[i][j] += inc[i][j - 1];
			exc[i][j] += exc[i][j - 1];
		}
	}

	for (int xl = 1; xl <= n; xl++) {
		for (int xr = xl; xr <= n + 1; xr++) {
			int y1 = -1, y2 = -1;
			for (int y = 1; y <= n; y++) {

				// When Backtracking, you are counting potential rectangles
				// (so the overlap is included)
				while (y1 < n && (y1 < y || exc[y1][xr] - exc[y1][xl] == 0)) {
					y1++;
				}
				while (y2 < n && (y2 < y || inc[y2][xr] - inc[y2][xl] == 0)) {
					y2++;
				}
				tot += y2 - y1;
			}			
		}
	}

	cout << tot << endl;
}