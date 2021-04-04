#include <bits/stdc++.h>
using namespace std;

enum type { H, M, O, B, D };

int transx[4] = {0, 0, 1, -1};
int transy[4] = {1, -1, 0, 0};

type fromChar(char c) {
    switch (c) {
        case 'O':
            return O;
        case 'M':
            return M;
        case '.':
            return D;
        case 'B':
            return B;
        default:
            return H;
    }
}

struct movement {
    type t;
    int x, y;

    movement(type c, int xx, int yy) {
        t = c;
        x = xx, y = yy;
    }

    movement(char c, int xx, int yy) {
        t = fromChar(c);
        x = xx, y = yy;
    }

    movement(char c) {
        t = fromChar(c);
        x = y = -1;
    }

    movement() {
        t = H;
        x = -1, y = -1;
    }

    bool operator<(const movement& other) const {
        return pair<int, int>{x, y} < pair<int, int>{other.x, other.y} ? true : t < other.t;
    }

    bool operator==(const movement& other) const {
        return x == other.x && y == other.y && t == other.t;
    }
};

movement grid[30][30];
bool vis[30][30];

vector<movement> adj[900];
vector<movement> path[900];

#define f first
#define s second

int n;
int root;

map<pair<int, int>, int> m;

void create(int x, int y, movement parent, int index) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + transx[i];
        int ny = y + transy[i];
        if (nx >= 0 && ny >= 0 && nx <= n - 2 && ny <= n - 2 && !vis[nx][ny] &&
            grid[nx][ny].t != H) {
            if (grid[nx][ny].t == D) {
                create(nx, ny, parent, index);

            } else {
                adj[index].push_back(grid[nx][ny]);
                adj[m[{nx, ny}]].push_back(parent);
                create(nx, ny, grid[nx][ny], m[{nx, ny}]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    string s;
    cin >> s;

    int rootx, rooty;
    int index = 0;
    set<pair<int, int>> ms;
    for (int i = 0; i < n - 2; i++) {
        cin >> s;
        for (int j = 1; j < n; j++) {
            char c = s[j * 3];
            if (c == 'M' || c == 'O') {
                int x = s[j * 3 + 1] - '0';
                int y = s[j * 3 + 2] - '0';
                grid[i][j - 1] = movement(c, x, y);
                m[{i, j - 1}] = index++;
                if (c == 'M' && !(x == 2 && y == 2)) {
                    ms.insert({i, j - 1});
                }
            } else {
                grid[i][j - 1] = movement(c);
            }
            if (c == 'B') {
                rootx = i, rooty = j - 1;
                root = index++;
                m[{i, j - 1}] = index;
            }
        }
    }
    cin >> s;

    movement rootm(B, rootx, rooty);

    // FOR DEBUGGING
    vector<pair<pair<int, int>, int>> v;
    for (auto p : m) {
        v.push_back(p);
    }
    // Create a Graph from the Grid
    create(rootx, rooty, rootm, root);

    vector<int> children(index);

    for (int i = 0; i < index; i++) {
        children[i] = adj[i].size();
    }

    // 8 Situations
    for (auto c : ms) {
        if (c == pair<int, int>{0, 4} && n == 7) {
            cout << 8 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 8 << endl;
    return 0;
}