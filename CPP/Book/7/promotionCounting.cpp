#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bs, be, ss, se, gs, ge, ps, pe;

    cin >> bs >> be;
    cin >> ss >> se;
    cin >> gs >> ge;
    cin >> ps >> pe;

    int sp, gp, pp;

    pp = pe - ps;
    gp = ge - gs + pp;
    sp = se - ss + gp;

    cout << sp << '\n';
    cout << gp << '\n';
    cout << pp << '\n';
}