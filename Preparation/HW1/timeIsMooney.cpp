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
#define s first

void setIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int n, m, c;
vi mg;
int maxMooney = 0;

vi adj[1001];
bool visited[1001];
int profit[1001][1001];

void bfsl(int start) {
	queue<pii> q;
	q.push({start, 0});
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if(cur.s >= 1000) continue;		
		for(int next: adj[cur.f]) {
			if (profit[cur.s + 1][next] < profit[cur.s][cur.f] + mg[next]) {
				profit[cur.s + 1][next] = profit[cur.s][cur.f] + mg[next];
				q.push({next, cur.s + 1});
			}
		}
	}
}

void bfs(int start){
    deque<pii> dq;
    // pair stores node, moves
    dq.emplace_back(start, 0);
    while(dq.size()>0){
        pii cur = dq.front(); dq.pop_front();
        if(cur.second>=1000) continue;
        for(int next: adj[cur.first]){
            if(profit[cur.second+1][next]< profit[cur.second][cur.first] + mg[next]){
                profit[cur.second+1][next] = profit[cur.second][cur.first] + mg[next];
                dq.emplace_back(next, cur.second+1);
            }
        }
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
	bfs(0);
	int best = 0;
	for (int i = 0; i <= 1000; i++) {
		best = max(best, profit[i][0] - i * i * c);
	}

	cout << best << endl;
}