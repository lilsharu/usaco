#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int n;

int b[1001][1001];
short cow[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    int totalBeauty = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int nc = cow[i][j] + cow[i + 1][j] + cow[i + 1][j + 1] + cow[i][j + 1];
            while (nc < 2) {
                int mb = -1;
                pii p;
                for (int x = i; x <= i + 1; x++) {
                    for (int y = j; y <= j + 1; y++) {
                        if (!cow[x][y] && b[x][y] > mb) {
                            mb = b[x][y];
                            p = {x, y};
                        }
                    }
                }

                totalBeauty += b[p.f][p.s];
                cow[p.f][p.s] = 1;
                nc++;
            }
        }
    }

    cout << totalBeauty << endl;
}