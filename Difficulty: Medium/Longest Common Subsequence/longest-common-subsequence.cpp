//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(string &a, string &b, int n, int m, vector<vector<int>>& t){
        if (m==0 || n==0) return 0;
        if (t[n][m] != -1) return t[n][m];
        if (a[n-1] == b[m-1]){
            return t[n][m] = 1 + helper(a, b, n-1, m-1, t);
        }
        return t[n][m] = max(helper(a, b, n, m-1, t), helper(a, b, n-1, m, t));
    }
    int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (m==0 || n==0) return 0;
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        return helper(text1, text2, n, m, t);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends