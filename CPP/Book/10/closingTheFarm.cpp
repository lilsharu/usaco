#include <bits/stdc++.h>

using namespace std;

struct barn {
    int pos;
    bool isOpen;
    barn(int _pos): pos(_pos) {}
    barn() {}

    bool operator<(const barn& a) const {
        return pos < a.pos;
    } 
};

int n, m;
int current = 0;

barn barns[3000];
vector<barn> adj[3000];
set<barn> opened;
bool visited[3000][3000];

void dfs(int node) {
    visited[current][node] = true;
    for (barn next : adj[node]) {
        if (!visited[next.pos] && next.isOpen) {
            dfs(next.pos);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        barns[i] = barn(i);
        opened.insert(barns[i]);
    }
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(barns[b]);
        adj[b].push_back(barns[a]);
    }
    delete &a;
    delete &b;

    int toClose;
    loop:
    for (int i = 0; i < n; i++) {
        cin >> toClose;
        toClose--;
        opened.erase(barns[toClose]);
        
        current = (*opened.begin()).pos;
        dfs(current);
        for (int j = 0; j < n; j++) {
            if (barns[j].isOpen && !visited[i][barns[j].pos]) {
                cout << "NO" << '\n';
                goto loop;
            }
        }

        cout << "YES" << '\n';
    }

    return 0;
}