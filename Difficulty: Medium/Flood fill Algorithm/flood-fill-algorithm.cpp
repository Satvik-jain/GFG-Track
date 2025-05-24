class Solution {
  public:
    void bfs(int n, int m, int i, int j, int color, vector<vector<int>> & grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        int old_color = grid[i][j];
        if(old_color == color) return;
        grid[i][j] = color;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i: {-1, 0, 1}){
                for(int j: {-1, 0, 1}){
                    int nr = r+i;
                    int nc = c+j;
                    if(nr<0||nr>n-1||nc>m-1||nc<0) continue;
                    if(abs(i)+abs(j) == 2) continue;
                    if(grid[nr][nc] == old_color){
                        grid[nr][nc] = color;
                        q.push({nr,nc});
                        }
                    }
                }
            }
        }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        bfs(n, m, sr, sc, newColor, image);
        return image;
    }
};