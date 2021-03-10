#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

vector<string> spot;
vector<string> plan;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("cownomics");

	int n, m;
	cin >> n >> m;

	spot.resize(n);
	plan.resize(n);

	for (int i = 0; i < n; i++) cin >> spot[i];
	for (int i = 0; i < n; i++) cin >> plan[i];

	int mingap = m;
	// Test Each substring
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < min(mingap, m - i); j++) {
			unordered_set<string> spst;
			for (string s : spot) {
				spst.insert(s.substr(i, j));
			}
			bool found = true;
			for (string s : plan) {
				if (spst.count(s.substr(i, j))) {
					found = false;
					break;
				}
			}
			if (found) {
				mingap = min(mingap, j);
				break;
			}
		}
	}

	cout << mingap << endl;
}