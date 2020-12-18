#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

struct cow {
    int x, d, w;
    
    bool operator<(const cow& b) {
        return x < b.x;
    }
};


int n, l, wMax = 0, wCurr = 0;

vector<cow> v;

int main() {
    setIO("meetings");
    cin >> n >> l;

    v = *new vector<cow>(n);

    FORN {
        cow c;
        cin >> c.w >> c.x >> c.d;
        wMax += c.w;
        v[i] = c;
    }

    cow start;
    start.w = 0;
    start.x = 0;
    start.d = 0;

    v.pb(start);

    cow end;
    end.w = 0;
    end.x = l;
    end.d = 0;
    
    v.pb(end);

    int t;
    for (t = 0; wCurr * 2 < wMax; t++) {
        sort(v.begin(), v.end());

        int b = 1E9, x;

        for (int i = 0; i < n - 1; i++) {
            int dist = v[i + 1].x - v[i].x;
            if (v[i].d == 1 && v[i + 1].d == -1) {
                if (dist < b) {
                    x = i; 
                } 
            } else if (v[i].d == 0) {
                wCurr += v[i + 1].w;
                auto it = v.begin() + i + 1;
                v.erase(it);
            }
        }

        int t = (b + 1) / 2 + 1;

        FORN {
            if (!(i == x || i == x + 1)) {
                v[i].x += t * v[i].d;                    
            } else {
                
            }
        }
    }
}