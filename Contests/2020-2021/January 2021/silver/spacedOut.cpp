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

int val[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val[i][j];
        }
    }

    int sol = 0;

    int t = 0;
    for (int i = 0; i < n; i+= 2) {
        for (int j = 0; j < n; j++) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int i = 1; i < n; i+= 2) {
        for (int j = 0; j < n; j++) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int j = 1; j < n; j+= 2) {
        for (int i = 0; i < n; i++) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int j = 0; j < n; j+= 2) {
        for (int i = 0; i < n; i++) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i % 2; j < n; j += 2) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1 - (i % 2); j < n; j += 2) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = (i % 2 == 0 ? 0 : 2); j < n; (j % 2 == 0 ? j ++ : j += 3)) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = (i % 2 == 0 ? 2 : 0); j < n; (j % 2 == 0 ? j ++ : j += 3)) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int j = 0; j < n; j++) {
        for (int i = (j % 2 == 0 ? 0 : 2); i < n; (i % 2 == 0 ? i ++ : i += 3)) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    t = 0;
    for (int j = 0; j < n; j++) {
        for (int i = (j % 2 == 0 ? 2 : 0); i < n; (i % 2 == 0 ? i ++ : i += 3)) {
            t += val[i][j];
        }
    }

    sol = max(sol, t);

    cout << sol << endl;
}