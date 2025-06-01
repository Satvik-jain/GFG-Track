class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int i = temp.first.first;
            int j = temp.first.second;
            int dis = temp.second;
            for (int a:{-1,0,1}){
                for (int b:{-1,0,1}){
                    int r = i+a;
                    int c = j+b;
                    if(abs(a) + abs(b) == 2) continue;
                    if(r < 0 || c < 0 || r >= n || c >= m){
                        continue;
                    }
                    else{
                        if(grid[r][c] == 0 && ans[r][c]==0){
                            ans[r][c] = dis+1;
                            q.push({{r,c}, dis+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};