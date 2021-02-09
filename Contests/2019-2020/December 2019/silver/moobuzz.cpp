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

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("moobuzz");

	vi moos;
	for (int i = 1; i <= 15; i++) {
		if (!(i % 3 == 0 || i % 5 == 0)) {
			moos.pb(i);
		}
	}
	
	ll n;
	cin >> n;
	
	ll numGroups = (n - 1) / moos.size();
	ll addition = (n - 1) % moos.size();

	ll total = numGroups * 15 + moos[addition];
	
	cout << total << endl;
}