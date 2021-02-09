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
#define val first
#define ind second

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("sort");

	int n;
	cin >> n;

	vpi v(n);
	
	fforn cin >> v[i].val, v[i].ind = i;

	sort(all(v), [](pii &a, pii &b) -> bool {
		return a.val < b.val || a.val == b.val && a.ind < b.ind; 
	});

	int ans = 0;
	ff0r(i, n) {
		ans = max(ans, v[i].ind - i);
	}
	
	cout << ans + 1 << endl;
}