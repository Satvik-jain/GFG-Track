class Solution {
  public:
    bool dfs(vector <int> adj[], vector<int> v, vector<int> pv, int i){
        v[i] = 1;
        pv[i] = 1;
        for (auto j: adj[i]){
            if (v[j] == -1){
                if (dfs(adj, v, pv, j)) return true;

            }
            if (v[j] == 1 && pv[j] == 1) return true;
        }
        pv[i]=!pv[i];
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector <int> vis(V, -1);
        vector <int> path_vis(V, -1);
        for (int i = 0; i < V; i++){
            if(vis[i]==-1){
                if (dfs(adj, vis, path_vis, i)) return true;
            }
        }
        return false;
    }
};