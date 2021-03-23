  
# Love Rescue
  
## CodeForces
  
### Contest ID 939
  
#### Problem D
  
The most important observation is that, as long as one letter is connected to another through any possible path, it can be transformed to that letter. In other words, as long as two letters are in the same component, they can be exchanged / swapped. Therefore, all we need to do is use a simple Disjoint Set Union.
  
We move through each index and, whenever we see a difference, we first check if the two letters are already in the same connected component. If they are, we don't need to worry about them since we can already map it. If not, we just add it to the list of connections and update our DSU with that union.
  
---
  
Note: While DSU is quick and easy, DFS should also work since the maximum size of any connected component is only 26
  
---
  
Here is my code:

```cpp
#include <bits/stdc++.h>
  
using namespace std;
struct DSU {
    vector<int> e;
  
    void init(int n) {
    e = vector<int>(n, -1);
    }
  
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
  
    bool sameSet(int a, int b) {
        return get(a) == get(b);
    }
  
    int size(int x) {
        return -e[get(x)];
    }
  
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};
  
vector<pair<int, int>> sol;
DSU d;
int tot = 0;
  
void combine(int a, int b) {
    if (a == b || d.sameSet(a, b)) return;
    tot++;
    sol.push_back({a, b});
    d.unite(a, b);
}
  
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
  
    string a, b;
    cin >> a >> b;
    d.init(26);
  
    // Check each index for comparison
    for (int i = 0; i < n; i++) {
        int c = a[i] - 'a', d = b[i] - 'a';
        combine(c, d);
    }
  
    cout << tot << endl;
  
    for (auto p : sol) {
        cout << (char)(p.first + 'a') << ' ' << (char)(p.second + 'a') << endl;
    }
  
    return 0;
}
  
```  
  