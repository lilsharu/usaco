#include <bits/stdc++.h>
using namespace std;

enum letter { O, M, B, X, D };

#define get_pos(i, j, num) ((i) * (num)) + (j)

int xchange[4] = {0, 0, 1, -1};
int ychange[4] = {1, -1, 0, 0};

struct lpos {
    letter l;
    int i, j;
    lpos(letter ll, int ii, int jj) : l(ll), i(ii), j(jj) {}
    lpos(char ll, int ii, int jj) : i(ii), j(jj) { l = ll == 'O' ? O : M; }
    lpos(char ll, char ii, char jj) {
        l = ll == 'O' ? O : M;
        i = (ii - '0') - 1;
        j = jj - '0' - 1;
    }
    lpos() : i(-1), j(-1), l(X) {}
};

struct searcher {
    vector<bool> vis;
    deque<pair<int, int>> path;
    int i, j;
    searcher(vector<bool> v, deque<pair<int, int>> p, int ii, int jj) {
        vis = v;
        path = p;
        i = ii;
        j = jj;
    }
};

lpos pos[25][25];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> root;
    for (int i = 0; i < n - 2; i++) {
        cin >> s;
        for (int j = 1; j < n - 1; j++) {
            char letter = s[j * 3], ipos = s[j * 3 + 1], jpos = s[j * 3 + 2];
            if (letter == 'B') {
                root = {i, j - 1};
                pos[i][j - 1] = lpos(B, -1, -1);
            } else if (letter == '#') {
                pos[i][j - 1] = lpos(X, -1, -1);
            } else if (letter == '.') {
                pos[i][j - 1] = lpos(D, -1, -1);
            } else {
                pos[i][j - 1] = lpos(letter, ipos, jpos);
            }
        }
    }

    int num = n - 2;
    queue<searcher> q;
    // Start Searching

    deque<pair<int, int>> start;
    vector<bool> mvis((num) * (num) + 5);
    mvis[get_pos(root.first, root.second, num)] = true;
    start.emplace_back(root.first, root.second);
    q.push(searcher(mvis, start, root.first, root.second));
    queue<deque<pair<int, int>>> pospath;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        pospath.push(cur.path);
        for (int i = 0; i < 4; i++) {
            int nextx = cur.i + xchange[i];
            int nexty = cur.j + ychange[i];
            if (nextx < num && nextx >= 0 && nexty < num && nexty >= 0 &&
                !pos[nextx][nexty].l == X &&
                !cur.vis[get_pos(nextx, nexty, num)]) {
                int posval = get_pos(nextx, nexty, num);
                if (pos[nextx][nexty].l != D) {
                    cur.path.push_back({nextx, nexty});
                    cur.vis[posval] = true;
                }
                q.push(searcher(cur.vis, cur.path, nextx, nexty));

                if (pos[nextx][nexty].l != D) {
                    cur.path.pop_back();
                    cur.vis[posval] = false;
                }
            }
        }
    }
    return 0;
}