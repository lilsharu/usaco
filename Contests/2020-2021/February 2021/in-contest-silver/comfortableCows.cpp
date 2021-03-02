#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define f first
#define s second

int graph[1001][1001];
int exist[1001][1001];
pair<int, int> val[1001][1001];
unordered_set<pair<int, int>> comfortableCows;

const pair<int, int> r = {-100001, -100001};

int add(int a, int b, vector<pair<int, int>>& added, pair<int, int> root = r) {
	if (exist[a][b]) return 0;

	graph[a][b + 1]++;
	graph[a][b - 1]++;
	graph[a + 1][b]++;
	graph[a - 1][b]++;
	exist[a][b] = true;

	int total = 0;
	if (exist[a + 1][b] && graph[a + 1][b] == 3) comfortableCows.insert({a + 1, b});
	else if (!(a + 1 == root.f && b == root.s) &&  exist[a + 1][b] && graph[a + 1][b] == 4) comfortableCows.erase({a + 1, b});

	if (exist[a - 1][b] && graph[a - 1][b] == 3) comfortableCows.insert({a - 1, b});
	else if (!(a - 1 == root.f && b == root.s) &&  exist[a - 1][b] && graph[a - 1][b] == 4) comfortableCows.erase({a - 1, b});

	if (exist[a][b + 1] && graph[a][b + 1] == 3) comfortableCows.insert({a, b + 1});
	else if (!(a == root.f && b + 1 == root.s) &&  exist[a][b + 1] && graph[a][b + 1] == 4) comfortableCows.erase({a, b + 1});

	if (exist[a][b - 1] && graph[a][b - 1] == 3) comfortableCows.insert({a, b - 1});
	else if (!(a == root.f && b - 1 == root.s) &&  exist[a][b - 1] && graph[a][b - 1] == 4) comfortableCows.erase({a, b - 1});

	for (auto it = comfortableCows.begin(); it != comfortableCows.end() && comfortableCows.size() != 0; it++) {
		auto a = *it;
		if (!exist[a.f + 1][a.s]) {
			total += 1 + add(a.f + 1, a.s, added, a);
			added.pb({a.f + 1, a.s});
		} else if (!exist[a.f - 1][a.s]) {
			total += 1 + add(a.f - 1, a.s, added, a);
			added.pb({a.f - 1, a.s});
		} else if (!exist[a.f][a.s + 1]) {
			total += 1 + add(a.f, a.s + 1, added, a);
			added.pb({a.f, a.s + 1});
		} else if (!exist[a.f][a.s - 1]) {
			total += 1 + add(a.f, a.s - 1, added, a);
			added.pb({a.f, a.s - 1});
		}
	}

	return total;
}

void remove(pair<int, int>& p) {
	exist[p.f][p.s] = false;
	graph[p.f][p.s + 1]--;
	graph[p.f][p.s - 1]--;
	graph[p.f + 1][p.s]--;
	graph[p.f - 1][p.s]--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;

	vector<pair<int, int>> added;
	for (int x = 0; x < n; x++) {
		int a, b;
		cin >> a >> b;
		a++, b++;

		int total = add(a, b, added);
		cout << total << endl;

		for (auto a : added) {
			remove(a);
		}
		added.clear();
	}
}