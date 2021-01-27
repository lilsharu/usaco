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
    setIO("swap");

    int n, m, k;
    cin >> n >> m >> k;

    vi trans(n);
    for (int i = 0; i < n; i++) {
        trans[i] = i;
    }

    for (int i = 0; i < m; i++) {
        read2(a, b);
        a--; b--;
        while (a < b) {
            int temp = trans[a];
            trans[a] = trans[b];
            trans[b] = temp;
            a++; b--;
        }
    }

    vector<int> sol(n);
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        vector<int> cycles;
        cycles.pb(i);
        int next = trans[i];
        while (next != i) {
            visited[next] = true;
            cycles.pb(next);
            next = trans[next];
        }

        int cycleSize = cycles.size();
        int movement = k % cycleSize;

        for (int j = 0; j < cycleSize; j++) {
            sol[cycles[j]] = cycles[(j + movement) % cycleSize];
            // sol[cycles[(j + movement) % cycleSize]] = cycles[j];
        }
    }

    for (auto a : sol) {
        cout << (a + 1) << endl;
    }
}