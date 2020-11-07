#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, m;

int parent[3000];

int find(int x) {
    if (x == parent[x]) return x;
    else return find(parent[x]);
}

void unify(int a, int b) {
    int c = find(a);
    int d = find(b);
    if (c != d) {
        parent[d] = c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        unify(a, b);
    }
    
}