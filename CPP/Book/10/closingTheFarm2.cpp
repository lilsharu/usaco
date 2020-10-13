#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, m;

vector<int> adj[3000];
vector<int> removed;

bool visited[3000][3000][3000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int toRemove;
    for (int i = 0; i < n; i++) {
        cin >> toRemove;

        bool connected = true;

        for (int a : adj[toRemove]) {
            adj[a].erase(find(adj[a].begin(), adj[a].end(), toRemove));
            if (adj[a].size() > 0) continue;
            else {
                connected = false;
                break;
            }
        }

        string output = connected ? "YES" : "NO";

        cout << output << '\n';
    }

}