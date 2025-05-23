class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        queue<int> q;
        q.push(0);
        vector <int> vis(n,0);
        vis[0] = 1;
        vector<int> v;
        // v.push_back(0);
        while(!q.empty()){
            int temp = q.front();
            v.push_back(temp);
            q.pop();
            vis[temp] = 1;
            for (auto it: adj[temp]){
                if(vis[it]==0){
                    q.push(it);

                    vis[it]++;
                }

            }
        }
        return v;
    }
};