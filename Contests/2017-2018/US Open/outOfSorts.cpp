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

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, num = 0;

vi vals;

void bubbleSort() {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        num++;
        for (int i = 0; i < n - 1; i++) {
            if (vals[i] > vals[i + 1]) {
                auto temp = vals[i];
                vals[i] = vals[i + 1];
                vals[i + 1] = temp;
                sorted = false;
            }
        } 
    }
}

int main() {
    setIO("sort");

    cin >> n;
    vals.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    bubbleSort();

    cout << num << endl;
}