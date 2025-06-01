// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(); int m = grid[0].size();
        vector<pair<int, int>> v;
        set <vector<pair<int,int>>> s;
        queue <pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m , 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                v.clear();
                if (vis[i][j] == 0 && grid[i][j] == 1){
                    q.push({i,j});
                    while(!q.empty()){
                        int newi = q.front().first;
                        int newj = q.front().second;
                        q.pop();
                        for(int a: {-1, 0, 1}){
                            for (int b: {-1, 0, 1})
                            {
                                int r = newi+a;
                                int c = newj+b;
                                if (abs(a) + abs(b) == 2) continue;
                                if (r<0 || c<0 || r>n-1 || c > m-1){
                                    continue;
                                }
                                else{
                                    if(grid[r][c] == 1 && vis[r][c] == 0){
                                        vis[r][c] = 1;
                                        q.push({r, c});
                                        v.push_back({r-i, c-j});
                                    }
                                }
                            }
                        }
                    }
                }
                if(v.size()) s.insert(v);
            }
        }
        
//         cout << "Distinct Islands:\n";
// for (const auto& shape : s) {
//     cout << "[ ";
//     for (const auto& cell : shape) {
//         cout << "(" << cell.first << "," << cell.second << ") ";
//     }
//     cout << "]\n";
// }

        return s.size();
    }
};
