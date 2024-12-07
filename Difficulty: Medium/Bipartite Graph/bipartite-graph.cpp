//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int k = 0; k < graph.size(); k++){
            if (vis[k] == -1){
                vis[0] = k;
                queue<int> q;
                q.push(k);
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    for(int j: graph[temp]){
                        if (vis[j] == -1){
                            if(!vis[temp]) vis[j] = 1;
                            else vis[j] = 0; 
                            q.push(j);
                        }
                        else{
                            if(vis[j]!=vis[temp]) continue;
                            else return false; 
                        }
                    }
                }
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