#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

struct val {
    int a, v;

    val() {
        
    }
};

bool comp(const val& a, const val& b) {
    return a.v < b.v;
}

int main() {
    setIO("pairup");
    
    int n, m = 0; cin >> n;
    
    vector<val> arr(n);
    
    F0R(i, n) {
        val temp;
        cin >> temp.a >> temp.v;
        arr[i] = temp;
        m += temp.a;
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    int i = 0, j = n - 1, sol = INT_MIN;
    for (int i = 0; i < n/2; i++) {
        int val = arr[i].v + arr[j].v;
        sol = max(sol, val);
        arr[i].a--;
        arr[j].a--;
        if (arr[i].a > 0) i--;
        if (arr[j].a == 0) j--;
    }

    cout << sol << endl;
}