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

// Correct: 1, 8, 10
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("shuffle");

	int n;
	cin >> n;

	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i], v[i]--;
	vector<int> visited(n);
	vi val(n);

	int total = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (i == v[i]) {
				total++;
				visited[i] = true;
				continue;
			}
			int previous = i;
			int cur = v[i];
			int size = 1;
			visited[i] = size;
			while (!visited[cur]) {
				visited[cur] = ++size;
				val[cur] == i;
				previous = cur;
				cur = v[cur];
			}
			if (val[cur] == i) {
				total += visited[previous] - visited[cur] + 1;
				cur = previous;
				do {
					visited[cur] = -1;
					cur = v[cur];
				} while (cur != previous);
			}
		}
	}

	cout << total << endl;
	return 0;
}