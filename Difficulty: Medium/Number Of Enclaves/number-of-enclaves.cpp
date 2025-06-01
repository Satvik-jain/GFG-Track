// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> & v, vector<vector<int>>& grid, int i, int j){
        int n = grid.size(); int m = grid[0].size();
        v[i][j] = 1;
        for (int a : {-1, 0, 1}){
            for (int b: {-1, 0 , 1}){
                 int r= i+a;
                 int c = j+b;
                 if (abs(a) + abs(b) == 2) continue;
                 if(r<0||c<0||r>n-1||c>m-1) continue;
                 if (v[r][c] == 0 && grid[r][c] == 1){
                     dfs(v, grid, r, c);
                 }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> v(n , vector<int>(m, 0));
        for (int i : {0, n-1}){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && v[i][j] == 0)
                {
                    dfs(v, grid, i, j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for (int j : {0, m-1}){
                if(grid[i][j] == 1 && v[i][j] == 0)
                {
                    dfs(v, grid, i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for (int j =0; j < m ; j++){
                if(grid[i][j] == 1 && v[i][j] == 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
