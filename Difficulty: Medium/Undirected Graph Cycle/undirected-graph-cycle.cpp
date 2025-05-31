class Solution {
  public:
    bool dfs(int i, int old, vector<int> &vis, vector<int> V[]){
        for (int j: V[i]){
            if((vis[j] == 1) && (j != old)){
                return true;
            }
            if(!vis[j]){
                vis[j]=1;
                if (dfs(j, i , vis, V)) return true;
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int E = edges.size();
        vector<int> v[V];
        for (int i = 0; i < E; i++){
            v[edges[i][1]].push_back(edges[i][0]);
            v[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V, 0);
        int old = -1;
        bool ans = false;
        for(int j = 0; j < vis.size(); j++){
            if(!vis[j]){
                vis[j] = 1;
                ans = dfs(j, old, vis, v);
                if (ans) return ans;
            }
        }
        return ans;
    }
};