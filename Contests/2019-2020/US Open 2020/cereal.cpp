#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vpi cows;
int solution = 0;
vi taken;

// 10 / 10
// Strategy: Ad Hoc?
void promote(int i) {
    if (taken[cows[i].f] != -1) {
        int p = taken[cows[i].f];
        if (taken[cows[p].f] == -1) {
            taken[cows[p].s] = p;
            solution++;
            return;
        }
        while (taken[cows[p].s] != -1 && taken[cows[p].s] > p) {
            int t = p;
            p = taken[cows[p].s];
            taken[cows[p].s] = t;
        }
        if (taken[cows[p].s] == -1) {
            taken[cows[p].s] = p;
            solution++;
        }
    } else {
        taken[cows[i].f] = i;
        solution++;
    }
}

int main() {
    setIO("cereal");
    cin >> n >> m;

    cows.resize(n);
    taken = *(new vi(m, -1));

    for (int i = 0; i < n; i++) {
        cin >> cows[i].f >> cows[i].s;
        cows[i].f--; cows[i].s--;
    }

    vi solutions(n, -1);
    int end = -1;
    for (int i = n - 1; i >= 0; i--) {
        int j = i;
        int pos = cows[i].f;
        while (true) {
            if (taken[pos] == -1) {
                taken[pos] = j;
                solution++;
                break;
            } else if (taken[pos] < j) {
                break;
            } else {
                int k = taken[pos];
                taken[pos] = j;
                if (pos == cows[k].s) {
                    break;
                }
                j = k;
                pos = cows[k].s;
            }
        }
        solutions[i] = solution;
        if (solutions[i] == m) {
            end = i;
            break;
        }
    }

    if (end != -1) {
        int i = 0;
        while (i < end) {
            solutions[i++] = solutions[end];
        }
    }

    for (auto a : solutions) cout << a << endl;
}