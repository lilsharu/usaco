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
 * game: "Angry Cows". The premise, which she believes is completely original, is
 * that the player shoots a cow with a slingshot into a one-dimensional scene
 * consisting of a set of hay bales located at various points on a number line;
 * the cow lands with sufficient force to detonate the hay bales in close
 * proximity to her landing site, which in turn might set of a chain reaction
 * that causes additional hay bales to explode. The goal is to use a single cow
 * to start a chain reaction that detonates all the hay bales.
 *
 * There are N hay bales located at distinct integer positions x1,x2,…,xN on the
 * number line. If a cow is launched with power R landing at position x, this
 * will causes a blast of "radius R", engulfing all hay bales within the range
 * x−R…x+R. These hay bales then themselves explode (all simultaneously), each
 * with a blast radius of R−1. Any not-yet-exploded bales caught in these blasts
 * then all explode (all simultaneously) with blast radius R−2, and so on.
 *
 * Please determine the minimum amount of power R with which a single cow may be
 * launched so that, if it lands at an appropriate location, it will cause
 * subsequent detonation of every single hay bale in the scene
 */

int n;
ll m;
pair<ll, ll> mp;
vector<ll> v;

pair<ll, ll> findMid() {
    ll midIndexL = 0, prevDiffL = v[n - 1];
    ll midIndexR = n, prevDiffR = -v[n - 1];
    for (int i = 0; i < n; i++) {
        ll diff = (m - v[i]);
        if (diff > 0 && diff < prevDiffL) {
            prevDiffL = diff;
            midIndexL = i;
        } else if (diff > prevDiffR) {
            prevDiffR = diff;
            midIndexR = i; 
        }
    }

    return pair<ll, ll>(midIndexL, midIndexR);
}

bool check(ll r) {

    ll p1 = r;
    ll p2 = r;
    ll rp = m + r;
    ll lp = m - r;

    if (rp >= v[n - 1] && lp <= v[0]) return true;

    for (int i = mp.second; i < n && p1 > 0; i++) {
        while (i + 1 < n && rp > v[i + 1]) i++;
        p1 -= 1;
        rp = v[i] + p1; 
    }
    
    if (rp < v[n - 1]) return false;
    
    for (int i = mp.first; i >= 0; i--) {
        while(i - 1 >= 0 && lp < v[i - 1]) i--;
        p2 -= 1;
        lp = v[i] - p2;
    }
    
    return lp <= v[0];
}

int main() {
    setIO("angry");
    cin >> n;

    FORN {
        ll t;
        cin >> t;
        v.pb(2 * t);
    }

    sort(all(v));

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2) {
        cout << (double)(v[1] - v[0]) / 4 << endl;
        return 0;
    }

    m = (v[n - 1] + v[0]) / 2;
    mp = findMid();

    ll r = m - v[0];
    for (ll a = r; a >= 1; a /= 2) {
        while (check(r - a)) r -= a; 
    }

    cout << (double)(r / 2.0) << endl;
    return 0;
}