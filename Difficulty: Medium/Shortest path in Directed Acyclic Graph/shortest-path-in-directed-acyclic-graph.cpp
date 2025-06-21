// User function Template for C++
class Solution {
  public:
    void dfs(vector<pair<int, int>> adj[], int i, vector<int>& topo, vector<int>& vis){
        vis[i] = 1;
        for (auto j: adj[i]){
            if (vis[j.first] == -1) dfs(adj, j.first, topo, vis);
        }
        topo.push_back(i);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> topo;
        vector<int> vis(V, -1);
        for (int i =0; i < V; i++){
            if (vis[i] == -1)dfs(adj, i, topo, vis);
        }
        reverse(topo.begin(), topo.end());
        int MAX = 100000;
        vector<int> ans(V, MAX);
        ans[0] = 0;
        for (int i: topo){
            for (auto j: adj[i]){
                ans[j.first] = min(ans[j.first], ans[i] + j.second);
            }
        }
        for (int i = 0; i < V; i++){
            if (ans[i] == MAX) ans[i] = -1;
        }
        return ans;
    }
};
