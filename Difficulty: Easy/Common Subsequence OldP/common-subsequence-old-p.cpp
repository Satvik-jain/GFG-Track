//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution {
  public:
    int commonSubseq(string text1, string text2){
        // code here
        int n = text1.size();
        int m = text2.size();
        if (m==0 || n==0) return 0;
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        for(int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if (text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        return t[n][m]!=0 ? 1 : 0;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1 >> S2;
        Solution ob;
        cout << ob.commonSubseq(S1, S2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends