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

int n, b;
int d[251], bd[251], ba[251];

unsigned int test(int ind = 0, int cur = 0) {
	if (cur >= n - 1) return 0;

	// Check Possible to Move
	int cd = d[cur];
	unsigned int total = __INT_MAX__;
	for (int i = ind; i < b; i++) {
		if (bd[i] < cd) continue;
		int mp = 0, md = d[cur + 1];
		for (int j = cur + 1; j <= cur + ba[i]; j++) {
			if (d[j] <= bd[i]) if (md >= d[j]) {
				md = d[j];
				mp = j;
			}
		}
		if (!mp) continue;
		unsigned int it = test(i, mp);
		total = min(total, (i - ind) + it);
		if (it == 0) break;
	}
	return total;
}

// 3 / 10 --> Timeout
// Strategy: Brute Force

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("snowboots");

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> bd[i] >> ba[i];
	}

	cout << test() << endl;
}