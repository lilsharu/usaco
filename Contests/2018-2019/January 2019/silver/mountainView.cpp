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

bool obs[100001];

bool cmp(pii& a, pii& b) {
	return a.s - a.f == b.s - b.f ? a.f < b.f : (a.s - a.f) > (b.s - b.f);
	// return (a.f == b.f) ? a.s > b.s : a.f < b.f;
}

// 10 / 11
// Strategy: Brute Force
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("mountains");

	int n;
	cin >> n;

	vpi m(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		m[i].f = a - b;
		m[i].s = a + b;
	}

	int tot = n;

	sort(all(m));

	for (int i = 0; i < n; i++) {
		if (obs[i]) continue;
		for (int j = i + 1; j < n; j++) {
			if (obs[j]) continue;
			if (m[j].s <= m[i].s && m[j].f >= m[i].f) {
				tot--;
				obs[j] = 1;
			}
		}
	}

	cout << tot << endl;
}