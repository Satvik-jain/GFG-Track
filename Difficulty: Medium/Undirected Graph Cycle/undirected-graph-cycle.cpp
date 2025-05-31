class Solution {
  public:
    bool f(vector<int> v[], vector<int> &vis){
        for(int j = 0; j < vis.size(); j++){
            if(!vis[j]){
                queue<pair<int, int>> q;
                q.push({j, -1});
                vis[j] = 1;
                while(!q.empty()){
                    int temp = q.front().first;
                    // cout << temp << endl;
                    int old = q.front().second;
                    q.pop();
                    for (int i : v[temp]){
                        if((i != old) && (vis[i] == 1)) return true;
                        if (!vis[i]){
                            vis[i] = 1;
                            q.push({i, temp});
                        }
                    }
                } 
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
        return f(v, vis);
    }
};