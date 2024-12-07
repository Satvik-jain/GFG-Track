//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool dfs(int n, vector<int>& vis, vector<vector<int>> &adj, int ele, int adjacent){
        vis[ele] = 1;
        for (int j: adj[ele]){
            if(!vis[j]){
                if (dfs(n, vis, adj, j, ele)) return true;
            }
            else if(vis[j] == 1 && j!=adjacent){
                return true;
            }
            
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n , 0);
        for (int i =0; i < n ; i++){
            if (!vis[i]){
                int adjacent = -1;
                int ele = i;
                if(dfs(n, vis, adj, ele ,adjacent)) return true;
            }
        }
        return false;
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends