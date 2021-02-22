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

bool work[251][251];
int best = 251;

void test(int ind = 0, int boot = 0) {
	if (work[ind][boot]) return;
	work[ind][boot] = true;

	if (ind == n - 1) best = min(best, boot);

	for (int i = ind + 1; i < n && i - ind <= ba[boot]; i++) {
		if (bd[boot] >= d[i]) test(i, boot);
	}

	for (int i = boot; i < b; i++) {
		if (bd[i] >= d[ind]) test(ind, i);
	}
}

// 4 / 10 --> Timeout
// Strategy: Full Recursive Search

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

	test();

	cout << best << endl;
	return 0;
}