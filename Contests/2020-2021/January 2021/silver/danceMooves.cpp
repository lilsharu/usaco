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

vi trans;
vector<int> ans;
vector<int> additional[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    trans.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        trans[i] = i;
        additional[i].pb(i);
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int temp = trans[a];
        trans[a] = trans[b];
        trans[b] = temp;
        additional[trans[a]].pb(a);
        additional[trans[b]].pb(b);
    }

    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int next = trans[i];
        vi cycles = {i};
        while (next != i) {
            visited[next] = true;
            cycles.pb(next);
            next = trans[next];
        }

        unordered_set<int> *x = new unordered_set<int>();
        unordered_set<int> forCycle = *x;

        for (auto a : cycles) {
            copy(additional[a].begin(), additional[a].end(), inserter(forCycle, (forCycle).end()));
        }

        for (auto a : cycles) {
            ans[a] = (forCycle).size();
        }

        delete x;
    }

    for (auto a : ans) {
        cout << a << endl;
    }
}