#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;

struct customer {
    ll start, end, roomNum;

    bool operator < (const customer& b) const {
        return (start < b.start);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    vector<customer> customers;

    for (int i = 0; i < n; i++) {
        customer in;
        cin >> in.start >> in.end;

        customers.push_back(in);
    }

}
