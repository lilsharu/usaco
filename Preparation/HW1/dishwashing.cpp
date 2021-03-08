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
vi v;

bool check(int num) {
	if (num > n) return false;
	else if (num == 1 || num == 2) return true;
	else {
		for (int i = 0; i < num - 2; i++) {
			if (v[i] > v[i + 2] && v[i + 2] > v[i + 1]) return false;
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("dishes");

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	int val = 2, jump = n - 1;
	for (; jump >= 1; jump >>= 1) {
		while (check(val + jump)) val += jump;
	}

	cout << val << endl;
}