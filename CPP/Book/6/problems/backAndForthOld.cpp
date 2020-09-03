#include <bits/stdc++.h>

#define set unordered_set<int>
#define map unordered_map<int, int>

using namespace std;

set b1, b2, a1, a2, ans;
map m1, m2, ma1, ma2;

set clone(set aSet) {
    set toReturn;
    for (auto i : aSet) {
        toReturn.insert(i);
    }
    return toReturn;
}

void reset() {
    a1 = clone(b1);
    a2 = clone(b2);
    ma1 = m1;
    ma2 = m2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);

    int* temp = new int;
    for (int i = 0; i < 10; i++) {
        cin >> *temp;
        b1.insert(*temp);
        m1[*temp]++;
    }
    for (int i = 0; i < 10; i++) {
        cin >> *temp;
        b2.insert(*temp);
        m2[*temp]++;
    }
    delete temp;

    int combo = 0;

    reset();

    for (auto a : a1) {
        int sa1 = 1000, sa2 = 1000;
        sa1 -= a;
        sa2 += a;
        if (--ma1[a] == 0) {
            a1.erase(a);
        }
        ma2[a]++;
        set ab1 = a1, ab2 = a2;
        map mb1 = ma1, mb2 = ma2;
        for (auto b : ab2) {
            ab1 = a1, ab2 = a2;
            mb1 = ma1, mb2 = ma2;
            int sb1 = sa1, sb2 = sa2;
            sb2 -= b;
            sb1 += b;
            if (--mb2[b] == 0) {
                ab2.erase(b);
            }
            mb1[b]++;
            set ac1 = ab1, ac2 = ab2;
            map mc1 = mb1, mc2 = mb2;
            for (auto c : ac1) {
                ac1 = ab1, ac2 = ab2;
                mc1 = mb1, mc2 = mb2;
                int sc1 = sb1, sc2 = sb2;
                sc1 -= c;
                sc2 += c;
                if (--mc1[c] == 0) {
                    ac1.erase(c);
                }
                mc2[c]++;
                set ad1 = ac1, ad2 = ac2;
                map md1 = mc1, md2 = mc2;
                for (auto d : ad2) {
                    ad1 = ac1, ad2 = ac2;
                    md1 = mc1, md2 = mc2;
                    int sd1 = sc1, sd2 = sc2;
                    sd1 += d;
                    sd2 -= d;
                    ans.insert(sd1);
                    cout << sd1 << '\n';
                }
            }
        }
        reset();
    }

    cout << ans.size() << '\n';
}
