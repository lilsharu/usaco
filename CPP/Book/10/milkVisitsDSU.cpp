#include <bits/stdc++.h>

using namespace std;



int n, m;
string pos;

int parent[100000];
bool solution[100000];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    else {
        return find(parent[parent[parent[parent[parent[x]]]]]);
    }
}

void unify(int a, int b) {
    int c = find(a);
    int d = find(b);
    if (c != d) {
        parent[d] = c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin >> n >> m;
    cin >> pos;
    
    init(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        unify(a, b);
    }

    for (int i = 0; i < m; i++) {
        int a, b, x;
        char c;

        cin >> a >> b >> c;
        a--; b--;
        
        x = b;
        
        if (a == b) {
            solution[i] = c == pos.at(a);
            continue;
        } 
        
        if (pos.at(a) != pos.at(b) || pos.at(a) == c) {
            solution[i] = true;
            continue;
        } else {
            while (x != parent[x]) {
                x = parent[x];
                if (pos.at(parent[x]) == c) {
                    solution[i] = true;
                    break;
                } 
            }
        }

        if (!solution[i]) {
            x = a;
            while (x != parent[x]) {
                x = parent[x];
                if (pos.at(parent[x]) == c) {
                    solution[i] = true;
                    break;
                } 
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << solution[i] ? 1 : 0;
    }

    cout << '\n';
    return 0;
}