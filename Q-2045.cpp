/*
Q-2045, Second Minimum Time to Reach Destination

A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.


*/






class Solution {
public:
    using int2 = pair<int, int>;

    inline static int wtime(int step, int time, int change) {
        int ans=0;
        for(int i=0; i < step; i++) {
            int gr=ans/change;
            if (gr&1)  // If it's a red light
                ans=(gr+ 1)*change;
            ans+=time;
        }
        return ans;
    }

    static int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        vector<int> dist(n+1, INT_MAX), dist2(n+1, INT_MAX);
        queue<int2> q;  // {node, distance}
        q.emplace(1, 0);
        dist[1]=0;

        while (!q.empty()) {
            auto [x, d]=q.front();
            q.pop();
            for (int y : adj[x]) {
                int newD=d+1;
                if (newD < dist[y]) {
                    dist2[y]=dist[y];
                    dist[y]=newD;
                    q.emplace(y, newD);
                } 
                else if (newD>dist[y] && newD<dist2[y]) {
                    dist2[y]=newD;
                    q.emplace(y, newD);
                }
            }
        }

        int steps=dist2[n];
        if (steps == INT_MAX) return -1;
        return wtime(steps, time, change);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();