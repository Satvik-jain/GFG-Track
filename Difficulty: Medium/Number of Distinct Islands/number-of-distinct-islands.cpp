//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  
  private:
    vector<pair<int,int>> dfs(vector<vector<int>> & grid, vector<vector<int>>&vis,
                            int i, int j, int i0, int j0, vector<pair<int,int>>& v){
        vis[i][j] = 1;
        v.push_back({i-i0,j-j0});
        int a[] = {-1,0,1,0};
        int b[] = {0,1,0,-1};
        for (int k = 0; k < 4; k++){
            int r = i+a[k];
            int c = j+b[k];
            if (r >=0 && c >=0&& r < grid.size() && c<grid[0].size() && !vis[r][c] && grid[r][c] == 1){
                
                dfs(grid, vis, r, c, i0, j0, v);
            }
        }
        return v;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n  = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set <vector<pair<int,int>>> st;
        for (int i = 0; i < n ; i++){
            for (int  j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> v;
                st.insert(dfs(grid, vis, i , j, i, j, v));
                }
            }
        }
        // for (auto it: st){
        //     for (int i = 0; i < it.size(); i++){
        //         cout << it[i].first << " " << it[i].second << " ";
        //     }
        //     cout << endl;
        // }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends