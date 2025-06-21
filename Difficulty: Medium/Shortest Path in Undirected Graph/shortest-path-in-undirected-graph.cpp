class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<pair<int ,int>> q;
        q.push({src, -1});
        int MAX = 10000;
        vector<int> vis(adj.size(), -1);
        vector<int> ans(adj.size(), MAX);
        ans[src] = 0;
        int dis = 0;
        while(!q.empty()){
            int top = q.front().first;
            dis = ans[q.front().first] + 1;
            vis[top] = 1;
            q.pop();
            for (int i: adj[top]){
                if (vis[i] == -1){
                    // cout << dis;
                    q.push({i,top});
                    vis[i] = 1;
                    ans[i] = dis;
                }
            }
        }
        for (int i = 0; i< adj.size(); i++){
            if (ans[i] == MAX) ans[i] = -1;
        }
        // cout << endl;
        return ans;
    }
};