class Solution {
  public:
    void dfs(int node, vector<int> grid[], vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        for (int neighbor : grid[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, grid, visited, ans);
            }
        }
        ans.push_back(node); // push after exploring all neighbors
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> grid[V];
        for (auto &e : edges) {
            grid[e[0]].push_back(e[1]);
        }

        vector<bool> visited(V, false);
        vector<int> ans;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, grid, visited, ans);
            }
        }

        reverse(ans.begin(), ans.end()); // reverse post-order DFS result
        return ans;
    }
};
