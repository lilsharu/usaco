#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define f first
#define s second

int v[1002][1002];
int c[1002][1002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    int total = 0;
    start:
        int mb = 0;
        pii p = {-1, -1};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (v[i][j] > mb && !c[i][j] &&
            c[i - 1][j - 1] + c[i - 1][j] + c[i][j - 1] < 2 &&
            c[i - 1][j] + c[i - 1][j + 1] + c[i][j + 1] < 2 &&
            c[i + 1][j] + c[i + 1][j - 1] + c[i][j - 1] < 2 &&
            c[i + 1][j] + c[i + 1][j + 1] + c[i][j + 1] < 2) {
                    mb = v[i][j];
                    p.first = i; p.second = j;
                }
            }
        }

        if (p.f != -1) {
                c[p.f][p.s] = 1;
                total += v[p.f][p.s];
                goto start;
        }

    cout << total << endl;
}