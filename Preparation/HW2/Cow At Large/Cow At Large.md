  
# Cow At Large
  
## January 2018
  
### Gold
  
#### Problem 2
  
We can split this problem into two main parts. Where is the potential place for each farmer to start, and how many of those places are unnecessary.
  
The first part of the problem is simple. All we need to do is find all the exits, can easily be found by looking for leaves on the "tree" that can be formed by all the paths that Bessie can take. To find this, we can simply find a list of all the leaves by finding each child with only one path.
  
With all the leaves, or potential exits that Bessie can exploit, there are some that are not necessary if Bessie can be blocked from all of them beforehand. For example, if A is the parent of B and B is the parent of two leaves C and D, only one farmer is needed becuase that farmer can move to B and block the exits to both C and D. With this observation, we can determine that, for any given section of the graph, if a farmer can move to an ancestor node A at or before Bessie, only that exit is needed to block every exit that has A as its ancestor.
  
With these observations, we can come up with the following solution:
  
1. BFS from Bessie's starting point, or the root, and find the distances from all other nodes in the tree.
2. If any node in the BFS has no children, add it to the list of exit nodes.
3. Sort all the exit nodes by distance from Bessie (A node closer to Bessie can block out a node farther from it if it shares a common ancestor, so this avoids double counting and extra complexity).
4. For each exit node, find the farthest anscestor visitable (simply take the the floor of the distance divided by 2), add one to the total, and remove all other children (including exit nodes) from consideration.
  
Here is my implementation of this:
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
  
#define pb push_back
#define all(x) begin(x), end(x)
  
#define endl '\n'
#define f first
#define s second
  
void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
vi adj[100001];
vi dist;
vector<bool> vis;
  
int parent(int& a) {
    for (int next : adj[a]) {
        if (dist[next] < dist[a]) return next;
    }
    return a;
};
  
void clear(int& root) {
    queue<int> q;
    q.push(root);
  
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : adj[cur]) {
            if (!vis[next] && dist[next] > dist[cur]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("atlarge");
  
    int n, k;
    cin >> n >> k;
    k--;
  
    vi exits;
  
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
  
    queue<int> q;
    dist.resize(n, 1 << 30);
    q.push(k);
    dist[k] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (adj[cur].size() == 1) exits.pb(cur);
        else {
            for (auto next : adj[cur]) {
                if (dist[cur] + 1 < dist[next]) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
  
    // sort exits by distance from bessie
    sort(all(exits), [](int& a, int& b) {
        return dist[a] < dist[b];
    });
  
    vis.resize(n);
    int tot = 0;
    for (auto cur : exits) {
        if (vis[cur]) continue;
        int move = dist[cur] >> 1;
        int root = cur;
        while (move--) {
            root = parent(root);
        }
        tot++;
        clear(root);  
    }
  
    cout << tot << endl;
}
```  
  