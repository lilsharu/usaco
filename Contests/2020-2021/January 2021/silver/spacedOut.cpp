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

    // Test Rows
    int maxR = 0;

    for (int i = 0; i < n; i++) {
        int rm = 0;
        int total = 0;
        for (int j = 0; j < n; j += 2) {
            total += val[i][j];
        }

        rm = max(rm, total);

        total = 0;
        for (int j = 1; j < n; j += 2) {
            total += val[i][j];
        }

        rm = max(rm, total);
        maxR += rm;
    }

    // Test Column
    int maxC = 0;
    for (int j = 0; j < n; j++) {
        int cm = 0, tot = 0;
        for (int i = 0; i < n; i += 2) {
            tot += val[i][j];
        }
        cm = max(cm, tot);
        tot = 0;
        for (int i = 1; i < n; i += 2) {
            tot += val[i][j];
        }
        cm = max(cm, tot);
        maxC += cm;
    }

    cout << max(maxR, maxC) << endl;
}