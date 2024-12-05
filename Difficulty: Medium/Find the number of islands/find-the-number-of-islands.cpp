//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void traverse(vector<vector<int>>& vis, vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            i = temp.first;
            j = temp.second;
            q.pop();
            for (auto a: {-1,0,1}){
                for (auto b: {-1,0,1}){
                    if (i+a >= 0 && j+b >= 0 && i+a < vis.size() && j+b < vis[0].size()){
                        if(grid[i+a][j+b]=='1' && !vis[i+a][j+b]){
                            q.push({i+a,j+b});
                            vis[i+a][j+b] = 1;
                        }
                    }
                }
            }
        }
    }
    public:
    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    traverse(vis, grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends