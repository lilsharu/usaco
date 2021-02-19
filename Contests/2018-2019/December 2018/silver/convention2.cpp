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
int a[100001], t[100001], sen[100001];

bool cmp(int& x, int& y) {
	return a[x] < a[y];
}

// 10 / 10
// Strategy: Kind of like two pointers, but suing a set instead
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("convention2");

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> t[i];
		sen[i] = i;
	}

	sort(sen, sen + n, cmp);

	set<int> waiting;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		waiting.insert(sen[i]);
		int ct = a[sen[i]];
		while (waiting.size()) {
			auto next = waiting.begin();
			int nv = *next;
			waiting.erase(next);

			ans = max(ans, ct - a[nv]);
			ct += t[nv];
			while (i + 1 < n && a[sen[i + 1]] < ct) waiting.insert(sen[++i]);
		}
	}

	cout << ans << endl;
}