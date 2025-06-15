class Solution {
  public:
    void dfs(int i, vector<int> grid[], vector<int>& v, vector<int> & ans, stack<int>& s){
        v[i] = 1;
        for (auto j : grid[i]){
            if (v[j] == -1){
                dfs(j, grid, v, ans, s);
            }
        }
        s.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> grid[V];
        for (int i = 0; i < edges.size(); i++){
            grid[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> v(V, -1);
        vector<int> ans;
        
        stack<int> s;
        
        for(int i = 0; i < V; i++){
            if (v[i] == -1){
                dfs(i, grid, v, ans, s);
            }
        }
        // s to ans
        for (auto i: s){
            ans.push_back(i);
            s.pop();
        }
        return ans;
    }
};