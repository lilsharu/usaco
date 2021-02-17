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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	setIO("herding");
	
	int n; cin >> n;
	
	vi pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}

	sort(all(pos));

	int mi = n << 1, ma = 0;

	// First Maximum
	for (int i = 1; i < n - 2; i++) {
		ma += pos[i + 1] - pos[i];
	}

	ma += max(pos[1] - pos[0], pos[n - 1] - pos[n - 2]);

	// Now Minimum
	if (pos[n - 1] - pos[1] == n - 2 && pos[1] - pos[0] > 2) mi = 2;
	else if (pos[n - 2] - pos[0] == n - 2 && pos[n - 1] - pos[n - 1] > 2) mi = 2;
	else {
		// Find Largest Group, and find most remaining after group
		for (int i = 0; i < n; i++) {
			int j = i;
			while (j + 1 < n && pos[j + 1] - 1 == pos[j]) j++;
			mi = min(n - (j - i + 1), mi);
		}
	}

	cout << mi << endl << ma << endl;
	return 0;
}