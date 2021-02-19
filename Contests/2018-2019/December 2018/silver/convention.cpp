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

int n, m, c;
int ct[100001];

bool check(int x) {
	if (x < 0) return false;
	int b = m;
	int i = 0;
	while (b-- && i < n) {
		int j = i;
		while (j + 1 < n && ct[j + 1] - ct[i] <= x && j - i + 1 < c) j++;
		i = j + 1;
	}

	return i >= n;
}

// 10 / 10
// Strategy: Binary Search on the Answer
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("convention");

	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		cin >> ct[i];
	}

	sort(ct, ct + n);

	int hi = ct[n - 1] - ct[0] + 1;
	int lo = 0;

	for(hi++; lo < hi;) {
		int mid = lo + ((hi - lo) >> 1);
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
}