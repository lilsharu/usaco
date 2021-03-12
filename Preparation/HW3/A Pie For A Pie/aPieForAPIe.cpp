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

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

struct pie {
	int b, e, i;
};

bool cmpB(pie &a, pie &b) {
	return a.b > b.b;
}

bool cmpE(pie &a, pie &b) {
	return a.e > b.e;
}

bool cmpI(pie &a, pie &b) {
	return a.i > b.i;
}

int n, d;

vector<pie> bess, els;

vector<pie> b0, e0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("piepie");

	cin >> n >> d;

	bess.resize(n);
	els.resize(n);

	for (int i = 0; i < n; i++) {
		int b, e;
		cin >> b >> e;
		pie p;
		p.b = b;
		p.e = e;
		p.i = i;
		if (b == 0 || e == 0) b0.pb(p);
		bess[i] = p;
	}

	for (int i = 0; i < n; i++) {
		int b, e;
		cin >> b >> e;
		pie p;
		p.b = b;
		p.e = e;
		p.i = i;
		els[i] = p;
	}

	sort(all(bess), cmpE);
	sort(all(els), cmpB);


}