//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if (n==0) return 0;
        int prev = 1;
        int prev2 = 0;
        for (int i = 2; i < n+1; i++){
            int curr = prev+ prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends