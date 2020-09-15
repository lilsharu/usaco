#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct specialCow {
    ll min, max;
};
bool cowComp(specialCow a, specialCow b) {
    return (a.max - a.min) < (b.max - b.min);
}


ll n, c;
vector<ll> chickens;
specialCow cows[20000];

int search(ll min, ll max, ll low,ll high) {
    int mid = (high + low)/2;
    if (chickens[mid] >= min && chickens[mid] <= max) {
        return mid;
    }

    if (high < low) return -1;

    if (chickens[mid] > max) {
        return search(min, max, low, mid - 1);
    }
    else return search(min, max, mid + 1, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    cin >> c >> n;

    for (int i = 0; i < c; i++) {
        ll temp;
        cin >> temp;
        chickens.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        specialCow c;
        cin >> c.min >> c.max;
        cows[i] = c;
    }

    sort(cows, cows + n, cowComp);
    sort(chickens.begin(), chickens.end());

    int nums = 0;
    for (int i = 0; i < n; i++) {
        int chickIndex = search(cows[i].min, cows[i].max, 0, c - 1);
        if (chickIndex == -1) continue;
        nums++;
        if (i + 1 <= chickens.size())
            chickens.erase(chickens.begin() + i);
    }

    std::cout << nums << '\n';
}