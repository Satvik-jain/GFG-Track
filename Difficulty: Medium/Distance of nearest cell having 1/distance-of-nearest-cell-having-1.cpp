//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    void helper(vector<vector<int>>& mat){
        vector<vector<int>> vis(mat.size(), vector<int> (mat[0].size(), 0));
        int m =mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>,int>> q;
        int step = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    mat[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({{i, j},step});
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            step = q.front().second;
            q.pop();
            for(int i: {-1,0,1}){
                for (int j: {-1,0,1}){
                    if (abs(i) + abs(j) == 2) continue;
                    int r = a+i;
                    int c = b+j;
                    if(r>=0&& c>=0&& r<mat.size()&& c<mat[0].size()){
                        if(!vis[r][c] && mat[r][c] == 0){
                            mat[r][c] = step+1;
                            vis[r][c] = 1;
                            q.push({{r,c},step+1});
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        int m =mat.size();
        int n = mat[0].size();
        helper(mat);
        return mat;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends