class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        int n = edges.size();
        int m = edges[0].size();
        queue <int> q;
        vector<int> v(n, -1);
        
        int n2 = 0;
        for (auto& edge : edges) {
            n2 = max(n2, max(edge[0], edge[1]));
        }

        vector<vector<int>> adj(n2 + 1);
    
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        
        q.push(0);
        v[0] = 0;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for (int i: adj[temp]){
                if (v[i]==-1){
                    v[i] = !v[temp];
                    q.push(i);
                }
                else{
                    if (v[i] == v[temp]) return false;
                }
            }
        }
        return true;
    }
};