#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

int n, k;
map<int, int> ng;
vi v;

bool work(int gap) {
	if (gap < 0) return false;
	ng[gap] = 0;

	for (int i = 0; i < n; i++) {
		int start = v[i];
		while (i + 1 < n && v[i] - v[i + 1] <= gap) i++;

		ng[gap]++;
	}

	return ng[gap] <= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	set<int> periods;
	periods.insert(0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a = (a + 11) / 12;
		periods.insert(-a);
	}

	if (periods.size() + 1 <= k) {
		cout << periods.size() * 12 << endl;
		return 0;
	}

	v.resize(periods.size());

	n = 0;
	for (auto a : periods) {
		v[n++] = -a;
	}

	int low = v[0], jump = v[0];
	for (; jump >= 1; jump >>= 1) {
		while (work(low - jump)) low -= jump;
	}

	ll total = 0;
	for (int i = 0; i < n - 1; i++) {
		int start = v[i];
		while (i + 1 < n && v[i] - v[i + 1] <= low) i++;

		total += (start - v[i] + 1) * 12;
	}

	if (k > ng[low]) {
		total -= (k - ng[low]) * low * 12;
	}

	cout << total << endl;
}