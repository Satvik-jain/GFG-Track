class Solution {
  public:
  
    bool dfs(vector<int> adj[], vector<int> &v, int i, int color){
        v[i] = color;
        for (int j : adj[i]){
            if (v[j]==-1){
                if (!dfs(adj, v, j, !color)) return false;
            }
            else{
                if (v[j] == color) return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector <int> v(V, -1);
        
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        };
                }
            }
        
        for (int i = 0; i < V; i++) {
            if (v[i] == -1) {  // Fixed: only start DFS for unvisited vertices
                if (!dfs(adj, v, i, 0)) {
                    return false
        }
        return true;
    }
};