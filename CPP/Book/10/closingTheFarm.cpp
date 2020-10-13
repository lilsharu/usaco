#include <bits/stdc++.h>

using namespace std;

struct barn
{
    int pos;
    bool isOpen;
    barn(int _pos) : pos(_pos), isOpen(true) {}
    barn() {}

    bool operator<(const barn &a) const
    {
        return pos < a.pos;
    }
};

int n, m;
int current = 0;

barn barns[4];
vector<barn *> adj[4];
set<barn> opened;
bool visited[4][4];

void dfs(int node)
{
    visited[current][node] = true;
    for (barn *next : adj[node])
    {
        barn n = *next;
        if (!visited[current][n.pos] && n.isOpen)
        {
            dfs(n.pos);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        barns[i] = barn(i);
        opened.insert(barns[i]);
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(&barns[b]);
        adj[b].push_back(&barns[a]);
    }

    int toClose;
loop:
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cin >> toClose;
            toClose--;
            opened.erase(barns[toClose]);
            barns[toClose].isOpen = false;
        }
        
        current = i;
        int toSearchFrom = (*opened.begin()).pos;
        dfs(toSearchFrom);
        for (int j = 0; j < n; j++)
        {
            if (barns[j].isOpen && !visited[i][barns[j].pos])
            {
                cout << "NO" << '\n';
                goto loop;
            }
        }

        cout << "YES" << '\n';
    }

    return 0;
}