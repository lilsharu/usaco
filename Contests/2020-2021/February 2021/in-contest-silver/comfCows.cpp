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

int x[100001];
int y[100001];
int cow[2001][2001];
int pos[2001][2001];
int total = 0;

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i] += 1001, y[i] += 1001;

		cow[x[i]][y[i]] = 1;
		pos[x[i] + 1][y[i]]++;
		pos[x[i] - 1][y[i]]++;
		pos[x[i]][y[i] + 1]++;
		pos[x[i]][y[i] - 1]++;
	}

	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			int x = i, y = j;
			while (cow[x][y] && pos[x][y] == 3) {
				if (!cow[x + 1][y]) {
					cow[x + 1][y] = 2;
					pos[x + 2][y]++;
					pos[x][y]++;
					pos[x + 1][y + 1]++;
					pos[x + 1][y - 1]++;
					x++;
					total++;
				}
				else if (!cow[x - 1][y]) {
					cow[x - 1][y] = 2;
					pos[x - 2][y]++;
					pos[x][y]++;
					pos[x - 1][y + 1]++;
					pos[x - 1][y - 1]++;
					x--;
					total++;
				}
				else if (!cow[x][y + 1]) {
					cow[x][y + 1] = 2;
					pos[x][y + 2]++;
					pos[x][y]++;
					pos[x + 1][y + 1]++;
					pos[x - 1][y + 1]++;
					y++;
					total++;
				}
				else (!cow[x][y - 1]) {
					cow[x][y - 1] = 2;
					pos[x][y - 2]++;
					pos[x][y]++;
					pos[x + 1][y - 1]++;
					pos[x - 1][y - 1]++;
					y--;
					total++;
				}
			}
		}
	}
}