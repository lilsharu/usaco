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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	k--;

	set<int> periods;
	periods.insert(0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a = (a + 11) / 12;
		periods.insert(a);
	}
	periods.insert(0);

	vi p(periods.begin(), periods.end());
	int gaps[p.size() - 1];
	
	for (int i = p.size() - 1; i >= 0; i--) {
		gaps[i - 1] = -(p[i] - p[i - 1] - 1);
	}

	sort(gaps, gaps + p.size() - 1);

	int totalAdditional = p.size() - 1;
	for (int i = 0; i < p.size() - 1; i++) {
		if (i < k) {
			continue;
		}
		totalAdditional -= gaps[i];
	}

	cout << totalAdditional * 12 << endl;
	return 0;
}