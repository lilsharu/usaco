#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int even = 0, odd = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        (t % 2 ? odd++ : even++);
    }

    if (odd - even >= 0) {
        if ((odd - even) % 3 != 1) {
            cout << (even * 2) + ((odd - even + 2) / 3) << endl;
        } else if (even > 0) {
            even--;
            cout << (even * 2) + ((odd - even + 2) / 3) << endl;
        } else {
            int total = (2 * odd) / 3;
            if (odd % 3 == 2) {
                total++;
            } else if (odd % 3 == 1) {
                
            }
            if (odd - even >= 0) {
                cout << (even * 2) + ((odd - even + 2) / 3) << endl;
            } else {
                cout << 2 * odd + (even % odd ? 0 : 1) << endl;
            }
        }
    } else {
        cout << 2 * odd + (even % odd ? 0 : 1) << endl;
        return 0;
    }

    return 0;
}