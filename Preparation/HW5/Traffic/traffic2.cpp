#include <bits/stdc++.h>

#include "traffic.h"
using namespace std;

#define pb push_back
#define f first
#define s second

void rawSummer(int root, int N, vector<bool> vis, vector<int> adj[],
               vector<long long> rawSum, int parent = -1) {
    vis[root] = true;
    for (int next : adj[root]) {
        if (!vis[root]) {
            rawSummer(next, N, vis, adj, rawSum, root);
        }
    }

    for (int next : adj[root]) {
        if (next != parent) {
            rawSum[root] += rawSum[next];
        }
    }
}

void weightSummer(int root, int N, vector<bool> vis, vector<int> adj[],
                  vector<long long> weightSum, vector<long long> rawSum,
                  int parent = -1) {
    vis[root] = true;
    for (int next : adj[root]) {
        if (!vis[root]) {
            weightSummer(next, N, vis, adj, weightSum, rawSum, root);
        }
    }

    for (int next : adj[root]) {
        if (next != parent) {
            weightSum[root] += weightSum[next] + rawSum[next];
        }
    }
}

int LocateCentre(int N, int pp[], int S[], int D[]) {
    vector<int> adj[N];

    for (int i = 0; i < N; i++) {
        adj[S[i]].pb(D[i]);
        adj[D[i]].pb(S[i]);
    }

    int start = 0;
    for (int i = 1; i < N; i++) {
        if (adj[i].size() > adj[start].size()) start = i;
    }

    // # Construct the Graphs
    vector<long long> rawSum(N);
    vector<long long> weightSum(N);
    vector<bool> vis(N);

    for (int i = 0; i < N; i++) {
        rawSum[i] = pp[i];
    }

    rawSummer(start, N, vis, adj, rawSum);
    vis = *new vector<bool>(N);
    weightSummer(start, N, vis, adj, weightSum, rawSum);

    // # Now Check Each One, Starting From the Root
    // _ Use BFS
    vis = *new vector<bool>(N);
    queue<pair<int, long long>> q;
    q.push({start, weightSum[start] + rawSum[start]});

    long long cmin = LLONG_MAX;
    int index = -1;

    while (!q.empty()) {
        pair<int, long long> cur = q.front();
        q.pop();
        vis[cur.f] = true;
        long long congestion = cur.s;

        congestion += (rawSum[start] - rawSum[cur.f]);
        congestion -= (rawSum[cur.f]);

        if (congestion < cmin) {
            cmin = congestion;
            index = cur.f;
        }

        for (int next : adj[cur.f]) {
            if (!vis[next]) {
                q.push({next, congestion});
            }
        }
    }

    return index;
}