#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void setIO(const string& name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

// Score: 10 / 10
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	setIO("dishes");

	int n;
	cin >> n;

	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<deque<int>> stacks(n);
	deque<int> removed;

	stacks[0].push_back(v[0]);
	int i = 1;
	for (; i < n; i++) {
		if (!removed.empty() && v[i] < removed.back()) {
			i--;
			break;
		}
		int ls = 0;
		while (!stacks[ls].empty() && v[i] > stacks[ls].front()) {
			ls++;
		}
		while (!stacks[ls].empty() && v[i] > stacks[ls].back()) {
			if (!removed.empty() && stacks[ls].back() < removed.back()) {
				i--;
				goto loop_end;
			}
			removed.push_back(stacks[ls].back());
			stacks[ls].pop_back();
		}
		stacks[ls].push_back(v[i]);
	}
	loop_end:
	cout << i + 1 << endl;
}
