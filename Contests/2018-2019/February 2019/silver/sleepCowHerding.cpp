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

vi p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("herding");

	int n;
	cin >> n;

	p.resize(n);
	
	for (int i = 0; i < n; i++) cin >> p[i];

	sort(all(p));

	// Or for efficiency, sum of all except gap of first and last, and then
	// add the greatest of the first and last
	int maximum = 0;	
	for (int i = 1; i < n - 1; i++) {
		while (i + 1 < n - 1 && p[i + 1] == p[i] + 1) i++;
		maximum += p[i + 1] - p[i] - 1;	
	}
	int m = 0;
	for (int i = n - 2; i > 0; i--) {
		while (i - 1 > 0 && p[i - 1] == p[i] - 1) i--;
		m += p[i] - p[i - 1] - 1;
	}

	maximum = max(maximum, m);

	int minimum = 1e9 + 1;

	if (p[n - 1] - p[1] == n - 2 && p[1] - p[0] > 2) {
		minimum = 2;
	} else if (p[n - 2] - p[0] == n - 2 && p[n - 1] - p[n - 2] > 2) {
		minimum = 2;
	} else {
		int i = 0, j = 0, best = 0;
		for (int i = 0; i < n; i++) {
			while (j < n - 1 && p[j + 1] - p[i] <= n - 1) j++;
			best = max(best, j - i + 1);
		}
		minimum = n - best;
	}

	cout << minimum << '\n' << maximum << endl;
}