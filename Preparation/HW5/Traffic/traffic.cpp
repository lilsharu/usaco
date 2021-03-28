#include "traffic.h"

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int LocateCentre(int N, int pp[], int S[], int D[]) {
    vector<int> adj[N];

    for (int i = 0; i < N; i++) {
        adj[S[i]].pb(D[i]);
        adj[D[i]].pb(S[i]);
    }

    long long cmin = LLONG_MAX;
    int cminind = 0;

    for (int i = 0; i < N; i++) {
        vector<long long> dist(N);
        vector<bool> vis(N);

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            vis[cur] = true;

            for (int next : adj[cur]) {
                if (!vis[next]) {
                    q.push(next);
                    dist[next] = dist[cur] + 1ll;
                }
            }
        }

        long long tot = 0;
        for (int i = 0; i < N; i++) {
            tot += pp[i] * dist[i];
        }

        if (tot < cmin) {
            cmin = tot;
            cminind = i;
        }
    }

    return cminind;
}