#include <iostream>
#include<set>
#include<algorithm>
#include<vector>

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

// 9 / 10 (Timeout)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("helpcross");

    int c, n;
    cin >> c >> n;

    vi chickens(c);
    multiset<pii> cows;

    for (int i = 0; i < c; i++) {
        cin >> chickens[i];
    }

    for (int i = 0; i < n; i++) {
        read2(a, b);
        cows.insert({b, a});
    }

    sort(all(chickens));

    int total = 0;

    for (int i = 0; i < c; i++) {
        for (auto p : cows) {
            if (p.f < chickens[i]) continue;
            else if (p.s > chickens[i]) continue;
            else {
                total++;
                cows.erase(cows.find(p));
                break;
            }
        }
    }

    cout << total << endl;
}