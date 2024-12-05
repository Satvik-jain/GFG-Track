//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    void bfs(vector<int>& vis, int i, vector<vector<int>>& adj)
    {
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for (auto it : adj[temp]){
                if (!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    int numProvinces(vector<vector<int>>& am, int V) {
        int n = am.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i!=j && am[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                bfs(vis, i, adj);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends