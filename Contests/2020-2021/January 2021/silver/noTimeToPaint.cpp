#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define endl '\n'

#define pb push_back

int ps[26][11001];
int ss[26][11001];

vi cols[26];

char val[10001];

int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;

    string a;
    cin >> a;

    for (int i = 0; i < n; i++) {
        cols[a[i] - 65].pb(i);
    }

    for (int i = 0; i < 26; i++) {
        if (cols[i].size() == 0) continue;
        if (cols[i].size() == 1) {
            ps[i][cols[i][0] + 1] = 1;
            ss[i][cols[i][0] + 1] = 1;
        } else {
            for (int j = 0; j < cols[i].size() - 1; j++) {
                int x = j;
                while (x + 1 < cols[i].size() && cols[i][x + 1] - cols[i][x] == 1) x++;
                if (x != j) {
                    ps[i][cols[i][j] + 1] = 1;
                    ss[i][cols[i][j] + 1] = 1;
                    j = x;
                } else {
                    bool split = false;
                    for (int k = 0; k < i && !split; k++) {
                        split = !(ps[k][cols[i][j + 1]] - ps[k][cols[i][j] - 1]);
                    }

                    if (split) {
                        ps[i][cols[i][j] + 1] = 1;
                        ss[i][cols[i][j] + 1] = 1;
                        ps[i][cols[i][j + 1] + 1] = 1;
                        ss[i][cols[i][j + 1] + 1] = 1;
                    } else {
                        ps[i][cols[i][j] + 1] = 1;
                        ss[i][cols[i][j] + 1] = 1;
                        cols[i].erase(cols[i].begin() + j + 1);
                        j--;
                    }
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            ps[i][j] += ps[i][j - 1];
        }
        for (int j = n; j >= 1; j--) {
            ss[i][j] += ss[i][j + 1];
        }
    }
}