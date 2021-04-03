#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi v;

bool cmp(ll& a, ll& b) { return a > b; }

bool check(ll h, ll& n, ll& k, ll& l) {
    if (h > n) return false;
    ll pos = k * l;
    ll res = 0;
    while (res < n && v[res] >= h) res++;
    while (res < h) {
        ll dif = h - v[res];
        if (dif > k || dif > pos) {
            return false;
        }
        pos -= dif;
        res++;
    }
    return res >= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, l;
    cin >> n >> k >> l;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    if (l >= n) {
        cout << min(n, v[n - 1] + k) << endl;
        return 0;
    }

    ll start = 0;
    for (ll jump = n; jump >= 1; jump >>= 1) {
        while (check(start + jump, n, k, l)) start += jump;
    }

    cout << start << endl;
}