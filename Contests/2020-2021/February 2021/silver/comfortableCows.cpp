#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int shift = 5001;

bool cow[1001 + shift][1001 + shift];
int num[1001 + shift][1001 + shift];

int total = 0;

void add(int a, int b) {
	cow[a][b] = true;

	num[a + 1][b]++;
	num[a - 1][b]++;
	num[a][b + 1]++;
	num[a][b - 1]++;
}

void update_q(int a, int b, queue<pii>& q) {
	if (num[a][b] == 3) q.push({a, b});
	if (num[a + 1][b] == 3 && cow[a + 1][b]) q.push({a + 1, b});
	if (num[a - 1][b] == 3 && cow[a - 1][b]) q.push({a - 1, b});
	if (num[a][b + 1] == 3 && cow[a][b + 1]) q.push({a, b + 1});
	if (num[a][b - 1] == 3 && cow[a][b - 1]) q.push({a, b - 1});
}

void insert(int a, int b) {
	add(a, b);

	queue<pii> q;
	update_q(a, b, q);

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		// assert(num[cur.f][cur.s] == 3 && cow[cur.f][cur.s]);

		int x = cur.f, y = cur.s;
		if (!cow[x + 1][y]) {
			total++;
			add(x + 1, y);
			update_q(x + 1, y, q);
		} else if (!cow[x - 1][y]) {
			total++;
			add(x - 1, y);
			update_q(x - 1, y, q);
		} else if (!cow[x][y + 1]) {
			total++;
			add(x, y + 1);
			update_q(x, y + 1, q);
		} else if (!cow[x][y - 1]) {
			total++;
			add(x, y - 1);
			update_q(x, y - 1, q);
		} else {
			// assert(false);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		a += shift, b += shift;
		if (cow[a][b]) total--;
		else insert(a, b);

		cout << total << endl;
	}
}