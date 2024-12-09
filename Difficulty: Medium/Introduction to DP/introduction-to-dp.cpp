//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int mod = 1e9 + 7;
class Solution {
  private:
    long long int f(int n , vector<int> &dp){
        if (n==0) return 0;
        if (n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (f(n-1, dp) + f(n-2, dp))%mod;
    }
  public:
    long long int topDown(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return f(n, dp)%(int(1e9+7));
    }
    long long int bottomUp(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends