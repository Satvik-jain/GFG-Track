//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &a, string &b) {
        // code here
        int n = a.size();
        int m = b.size();
        if (n == 0 || m == 0){
            return 0;
        }
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if (a[i-1] == b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return n+m-t[n][m]; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends