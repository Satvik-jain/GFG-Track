//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<int> & vis, vector<vector<int>> & adj, vector<int>&v, int i){
        vis[i] = 1;
        
        for(j : adj[i]){
            if (!vis[j]){
                v.push_back(j);
                dfs(vis, adj, v, j);
            }
        }
    }
    
    
    public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector <int> vis(adj.size(), 0);
        vector<int> v;
        v.push_back(0);
        for (int i = 0; i < adj.size(); i++){
            dfs(vis, adj, v, i);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends