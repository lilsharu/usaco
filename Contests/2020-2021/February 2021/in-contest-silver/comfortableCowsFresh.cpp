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

int pos[2001][2001];
bool cow[2001][2001];
int added[2001][2001];
bool visited[2001][2001];
vpi vis;
int total = 0;

int addThird(int a, int b, int x, int y, int c = 2) {
	if (visited[a][b]) return 0;
	visited[a][b] = true;
	vis.pb({a, b});
	if (pos[a][b] == c) {
		if (a + 1 != x && !cow[a + 1][b]) {
			return 1 + addThird(a + 1, b, a, b);
		} else if (a - 1 != x && !cow[a - 1][b]) {
			return 1 + addThird(a - 1, b, a, b);
		} else if (b + 1 != y && !cow[a][b + 1]) {
			return 1 + addThird(a, b + 1, a, b);
		} else {
			return 1 + addThird(a, b - 1, a, b);
		}
	}
	return 1;
}

int addSecond(int a, int b) {
	if (!cow[a + 1][b]) {
		return addThird(a + 1, b, a, b, 3);
	} else if (!cow[a - 1][b]) {
		return addThird(a - 1, b, a, b, 3);
	} else if (!cow[a][b + 1]) {
		return addThird(a, b + 1, a, b, 3);
	} else {
		return addThird(a, b - 1, a, b, 3);
	}
}

void add(int a, int b) {
	cow[a][b] = true;
	pos[a + 1][b]++;
	pos[a - 1][b]++;
	pos[a][b + 1]++;
	pos[a][b - 1]++;

	if (pos[a + 1][b] == 3 && cow[a + 1][b]) {
		added[a + 1][b] = addSecond(a + 1, b);
		total += added[a + 1][b];
	}
	else if (pos[a + 1][b] == 4 && cow[a + 1][b]) {
		total -= added[a + 1][b];
	}

	if (pos[a - 1][b] == 3 && cow[a - 1][b]) {
		added[a - 1][b] = addSecond(a - 1, b);
		total += added[a - 1][b];
	}
	else if (pos[a - 1][b] == 4 && cow[a - 1][b]) {
		total -= added[a - 1][b];
	}

	if (pos[a][b + 1] == 3 && cow[a][b + 1]) {
		added[a][b + 1] = addSecond(a, b + 1);
		total += added[a][b + 1];
	}
	else if (pos[a][b + 1] == 4 && cow[a][b + 1]) {
		total -= added[a][b + 1];
	}

	if (pos[a][b - 1] == 3 && cow[a][b - 1]) {
		added[a][b - 1] = addSecond(a, b - 1);
		total += added[a][b - 1];
	}
	else if (pos[a][b - 1] == 4 && cow[a][b - 1]) {
		total -= added[a][b - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		a+=1001, b+=1001;
		add(a, b);
		cout << total << endl;
		for (auto a : vis) {
			visited[a.f][a.s] = false;
		}
	}
}