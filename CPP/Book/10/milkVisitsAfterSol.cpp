#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define all(x) begin(x), end(x)

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

const int MX = 100005;

int n, m, comp[MX], num;
char chars[MX];

vi adj[MX];

void dfs(int x) {
    if (comp[x]) return;
    comp[x] = num;
    trav(c, adj[x]) {
        if (chars[c] == chars[x]) {
            dfs(c);
        }
    }
}

int main() {
    setIO("milkvisits");

    cin >> n >> m;

    string text; cin >> text;

    FOR(i, 1, n + 1) {
        chars[i] = text[i];
    }
    F0R(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(i, 1, n + 1) {
        if (!comp[i]) {
            num++;
            dfs(i); 
        }
    }
    FOR(i, 1, n + 1) {
        int a, b;
        char c;
        cin >> a >> b >> c;

        if (chars[a] == c || comp[a] != comp[b]) cout << '1';
        else cout << '0';        
    }
    cout << '\n';
    return 0;
}