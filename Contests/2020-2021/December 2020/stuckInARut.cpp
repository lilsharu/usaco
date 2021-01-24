#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef pair<int, int> pii;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

struct cow {
    int num, x, y;
    vi blocked {};
};

bool sortX(const cow &a, const cow &b) {
    return a.x < b.x;
}

bool sortY(const cow &a, const cow &b) {
    return a.y < b.y;
}

bool sortNum(const cow &a, const cow &b) {
    return a.num < b.num;
}

int n;
vector<cow> east, north;
vi total;

vector<cow> cows;

// 10 / 10

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 
    
    total = *new vi(n);
    
    for (int i = 0; i < n; i++) {
        char a;
        cow c;

        cin >> a >> c.x >> c.y; 

        c.num = i;
        
        if (a == 'E') {
            east.pb(c);
        } else {
            north.pb(c);
        }
    }

    sort(all(north), sortX);
    sort(all(east), sortY);
    
    for (int i = 0; i < north.size(); i++) {
        for (int j = 0; j < east.size(); j++) {
            auto nc = north[i];
            auto ec = east[j];

            if (nc.y > ec.y) continue;
            if (nc.x < ec.x) continue;

            int time = ec.y - nc.y;

            if (ec.x + time == nc.x) continue;
            else if (ec.x + time > nc.x) {
                ec.blocked.pb(nc.num);
                ec.blocked.insert(ec.blocked.end(), all(nc.blocked));

                east[j] = ec;
                north[i] = nc;

                break;
            } else {
                nc.blocked.pb(ec.num);
                nc.blocked.insert(nc.blocked.end(), all(ec.blocked)); 

                east[j] = ec;
                north[i] = nc;

                cows.pb(east[j]);
                
                east.erase(east.begin() + j);
                j--;
            }
        }
    }

    for (auto c : east) {
        cows.pb(c);
    }

    for (auto c : north) {
        cows.pb(c);
    }

    sort(all(cows), sortNum);

    for (auto a : cows) {
        cout << a.blocked.size() << endl;
    }
}