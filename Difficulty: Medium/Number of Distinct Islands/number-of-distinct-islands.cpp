// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<pair<int, int>> v;
                if (grid[i][j] == 1 && vis[i][j] == 0){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    // vis[i][j] = 1;
                    while(!q.empty()){
                        int temp_i = q.front().first;
                        int temp_j = q.front().second;
                        q.pop();
                        for (int a : {-1, 0, 1}){
                            for (int b : {-1, 0, 1}){
                                if (abs(a) + abs(b) == 2) continue;
                                int r = temp_i + a;
                                int c = temp_j + b;
                                if (r < 0 || c < 0 || r > n-1 || c > m-1) continue;
                                if (grid[r][c] == 1 && vis[r][c] == 0){
                                    q.push({r, c});
                                    vis[r][c] = 1;
                                    v.push_back({r-i, c-j});
                                }
                            }
                        }
                    }
                }
                if (v.size()) s.insert(v);
            }
        }
        return s.size();
    }
};
