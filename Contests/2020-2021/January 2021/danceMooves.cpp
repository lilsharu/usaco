#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n'
#define f first
#define s second

int n, k;
vpi swapper;
vi trans;

bool visited[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    swapper.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> swapper[i].f >> swapper[i].s;
    }

    trans.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        trans[i] = i;
    }

    for (auto s : swapper) {
        int temp = trans[s.f];
        trans[s.f] = trans[s.s];
        trans[s.s] = temp;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int start = trans[i];
            vi cycle;
            cycle.pb(i);
            while (start != i) {

            }
        }
    }
}