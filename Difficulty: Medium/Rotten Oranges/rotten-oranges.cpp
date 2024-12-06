//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid){
        queue <pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({{i,j},time});
                    vis[i][j]++;
                }
                if (grid[i][j] == 1)count++;
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            time = q.front().second;
            q.pop();
            int rows[] = {-1,0,1,0};
            int cols[] = {0,1,0,-1};
            for (int i = 0; i < 4 ; i++){
                int newr = a + rows[i];
                int newc = b + cols[i];
                // if (abs(i) + abs(j) == 2) continue;
                if (newr >= 0 && newc >= 0 && newr < grid.size() && 
                    newc < grid[0].size()){
                    if (grid[newr][newc] == 1 && vis[newr][newc] == 0){
                        vis[newr][newc] = 1;
                        grid[newr][newc] = 2;
                        q.push({{newr, newc},time + 1});
                        cnt++;
                    }
                
                }
            }
        }
        if(count!=cnt) return -1;
        else return time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int time = bfs(vis, grid);
        return time;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends