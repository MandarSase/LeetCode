class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> graph(n);
        vector<bool> visited(n, false);
        vector<int> minCost(n, 1e8);

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            graph[u].push_back({v, cost});
            graph[v].push_back({u, 2 * cost}); // Add Switch Too
        }

        // Dijkstra's Algorithm
        minCost[0] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0}); // {distance, node}

        while (!pq.empty() && !visited[n - 1]) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for (auto &[nei, cost] : graph[node]) {
                if (visited[nei]) continue;

                int newDist = dist + cost;
                if (newDist < minCost[nei]) {
                    minCost[nei] = newDist;
                    pq.push({newDist, nei});
                }
            }
        }

        return visited[n - 1] ? minCost[n - 1] : -1;
    }
};
