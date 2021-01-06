#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll distances(ll start, const vector<vector<ll>> &values)
{
    vll distances = vll(values.size(), -1);

    stack<ll> stack;
    distances[start] = 0;
    stack.push(start);

    while (!stack.empty())
    {
        ll val = stack.top();
        stack.pop();
        for (auto x : values[val])
        {
            if (distances[x] == -1)
            {
                distances[x] = distances[val] + 1;
                stack.push(x);
            }
            else if (distances[x] > distances[val] + 1)
            {
                distances[x] = distances[val] + 1;
                stack.push(x);
            }
        }
    }

    return distances;
}

int main()
{
    auto x = distances(
        0,
        vector<vector<ll>>{{1, 2}, {0, 3}, {0, 4}, {1, 4}, {2, 3}});
    for (auto a : x) {
        cout << a << " ";
    }
}
