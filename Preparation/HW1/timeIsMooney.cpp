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

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int n, m, c;
vi mg;
int maxMooney = 0;

vi adj[1001];
bool visited[1001];

struct dat {
	int index, t, me;
	dat(int ind, int t, int me) : index(ind), t(t), me(me){}
	dat(int ind) : index(ind) {t = 0, me = 0;}
};

void bfs() {
	queue<dat> q;
	q.push(dat(0));
	while (!q.empty()) {
		auto s = q.front();
		q.pop();
		visited[s.index] = true;
		auto t = s.t;
		auto me = s.me;
		if (s.index == 0 && t > 0) {
			auto meog = me;
			auto tog = t;
			while (c * t * t < me && me - c * t * t >= meog - c * tog * tog) {
				maxMooney = max(maxMooney, me - c * t * t);
				t += tog;
				me += meog;
			}
			continue;
		}

		for (auto a : adj[s.index]) {
			if (a == 0 || !visited[a] || me - c * t * t <= me + mg[a] - c * (t + 1) * (t + 1))
				q.push(dat(a, t + 1, me + mg[a]));
		}
		t++;
	}
}

// Idea: Find cycles with root (there are going to be a bunch of them) and find
// the maximum you can get with the cycle.
//
// Correct: 1, 10, 11
// Incorrect: 2, 5, 6
// Runtime Error or Memory Limit Exceeded: 3, 4, 9
// Timeout: 7, 8
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	setIO("time");

	cin >> n >> m >> c;
	mg.resize(n);

	for (int i = 0; i < n; i++) cin >> mg[i];

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
	}

	bfs();

	cout << maxMooney << endl;

}