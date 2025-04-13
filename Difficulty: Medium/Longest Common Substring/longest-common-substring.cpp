//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> t(n+1, vector<int>(m+1,0));
        vector<int> ans;
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if (s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                    ans.push_back(t[i][j]);
                }
                else{
                    
                    t[i][j] = 0;
                }
            }
        }
        if (ans.size()==0) return 0;
        return *max_element(ans.begin(), ans.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends