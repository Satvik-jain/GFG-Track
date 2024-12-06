//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n, 0);
        for (int j = 0; j < adj.size(); j++){
            if (!vis[j]){
                queue <pair<int,int>> q;
                q.push({j,-1});
                vis[j]++;
                while(!q.empty()){
                    int AdjEle = q.front().second;
                    int temp = q.front().first;
                    q.pop();
                    for(auto i : adj[temp]){
                        if(vis[i]!=0 && i!=AdjEle){
                            return true;
                        }
                        if(!vis[i]){
                            vis[i]=1;
                            q.push({i, temp});
                        }
                        
                    }
                    
                }
                
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