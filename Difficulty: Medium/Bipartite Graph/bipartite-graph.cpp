//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool dfs(vector<int>& vis, vector<vector<int>> & adj, int i){
        for (j: adj[i]){
            if (vis[j] == -1){
                vis[j] = !vis[i];
                dfs(vis, adj, j);
            }
            else if(vis[i] == vis[j]){
                return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        vector <int> vis(adj.size(), -1);
        for (int  i =0 ; i < adj.size(); i++){
            if(vis[i]==-1){
                vis[i] = 0;
                if (!dfs(vis, adj, i)) return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends