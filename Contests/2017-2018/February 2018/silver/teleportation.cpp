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

pii trans[100001];
int dif[100001];
int pos[100001];
int t[200002];

bool cmp(int& a, int &b) {
	return dif[a] > dif[b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("teleport");

	int n;
	cin >> n;

	int tot = 0;
	int next = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		trans[i].f = a;
		trans[i].s = b;
		dif[i] = abs(a - b);
		tot += dif[i];
		pos[i] = i;
		t[next++] = a;
		t[next++] = b;
	}

	for (int i = 0; i < (n << 1); i++) {
		
	}
}