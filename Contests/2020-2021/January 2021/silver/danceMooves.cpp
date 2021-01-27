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
vector<set<int>> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    trans.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        trans[i] = i;
        ans[i].insert(i);
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int temp = trans[a];
        trans[a] = trans[b];
        trans[b] = temp;
        ans[trans[a]].insert(trans[b]);
        ans[trans[b]].insert(trans[a]);
    }

    vector<bool> visited(n);

    return 0;
}