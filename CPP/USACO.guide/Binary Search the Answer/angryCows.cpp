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

/*
 * Bessie the cow has designed what she thinks will be the next big hit video
 * game: "Angry Cows". The premise, which she believes is completely original,
 * is that the player shoots cows with a slingshot into a one-dimensional scene
 * consisting of a set of hay bales located at various points on a number line.
 * Each cow lands with sufficient force to detonate the hay bales in close 
 * proximity to her landing site. The goal is to use a set of cows to detonate 
 * all the hay bales.
 * 
 * There are N hay bales located at distinct integer positions x1,x2,…,xN on the
 * number line. If a cow is launched with power R landing at position x, this
 * will causes a blast of "radius R", destroying all hay bales within the range 
 * x−R…x+R.
 * 
 * A total of K cows are available to shoot, each with the same power R. 
 * Please determine the minimum integer value of R such that it is possible to
 * use the K cows to detonate every single hay bale in the scene.
 */


int n, k;
vi hp;

bool check(int r) {
    vector<vi> arrayParts;
    if (k * r * 2 >= hp[n - 1] - hp[0]) return true;

    int index = 0;
    for (int i = 0; i < n - 1; i++) {
        if (hp[i + 1] - hp[i] >= 2 * r + 1 || i + 2 >= n) {
            vi temp; 
            copy(hp.begin() + index, hp.begin() + i + 1, back_inserter(temp));
            arrayParts.pb(temp);
            index = i + 1;
        }
    }

    int sum = 0;

    trav(x, arrayParts) {
        int gap = x.back() - x.front() + 1;
        sum += gap / (2 * r + 1) + (gap % (2 * r + 1) ? 1 : 0);
    }

    return sum <= k;
}

// 7/10

int main() {
    setIO("angry");

    cin >> n >> k;
    
    FORN {
        read(t);
        hp.pb(t);
    }

    sort(all(hp));
    
    if (hp.size() <= k) {
        cout << 0 << endl;
        return 0;
    }

    int lo = 0, hi = (hp[n - 1] - hp[0]) / 2;

    for (hi++; lo < hi;) {
        int mid = (lo + hi) / 2;
        check(mid) ? hi = mid : lo = mid + 1; 
    }

    cout << lo << endl;
    return 0;
}