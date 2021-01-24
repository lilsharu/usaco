#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define pb push_back

#define endl '\n'

int n, q;
string thing;

int nl[26][11001];
int sl[26][11001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    cin >> thing;

    for (int i = 0; i < n; i++) {
        nl[thing[i] - 65][i + 1] = 1;
    }

    vi stops;

    for (int i = 0; i < 26; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            nl[i][j] = nl[i][j] + nl[i][j - 1];
            if (nl[i][j] > nl[i][j - 1]) {
                stops.pb(j);
            } else if (stops[x] == j) {
                sl[i][j] = 1;
                x++;
            }
            sl[i][j] = sl[i][j] + sl[i][j - 1];
        }
    }

    vi solution(q);

    for (int x = 0; x < q; x++) {
        int start, end;
        cin >> start >> end;

        int total = 0;

        if (start != 1) {
            for (int i = 0; i < 26; i++) {
                if (nl[i][start] - nl[i][0]) total++;
            }
        }

        if (end != n) {
            for (int i = 0; i < 26; i++) {
                if (nl[i][n] - nl[i][end]) total++;
            }
        }

        solution[x] = total;
    }

    for (auto a : solution) {
        cout << a << endl;
    }

    return 0;
}