#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define endl '\n'

#define pb push_back

int ps[11001];
int ss[11001];

int cols[26];

char val[10001];

int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;

    string a;
    cin >> a;

    memset(cols, -1, 26);

    for (int i = 1; i <= n; i++) {
        int curchar = a[i - 1] - 'A';
        for (int c = 0; c < 26; c++) {
            cols[c] = min(curchar, cols[c]);
        }
        ps[i] = ps[i - 1];
        if (cols[curchar] < curchar) {
            ps[i]++;
        }
        cols[curchar] = curchar;
    }

    memset(cols, -1, 26);

    for (int i = n; i >= 1; i--) {
        int curchar = a[i - 1] - 'A';
        for (int c = 0; c < 26; c++) {
            cols[c] = min(curchar, cols[c]);
        }
        ss[i] = ss[i - 1];
        if (cols[curchar] < curchar) {
            ps[i]++;
        }
        cols[curchar] = curchar;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ps[a - 1] << ps[b - 1] << endl;
    }
}