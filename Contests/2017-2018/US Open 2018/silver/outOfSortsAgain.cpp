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

int n;
vi v, s;

// 10 / 10
// Strategy: Ad Hoc
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	setIO("sort");

	cin >> n;
	v.resize(n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v[i] = a;
		s[i] = a;
	}
	sort(all(s));

	map<int, int> rp;

	for (int i = 0; i < n; i++) {
		rp[s[i]] = i;
	}

	int num = 0;

	for (int i = 0; i < n; i++) {
		num = max(num, i - rp[v[i]]);
	}

	cout << num + 1 << endl;
}