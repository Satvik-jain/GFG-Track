//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  void helper(int k, vector <int>&v, int a){
      if(v.size() == 1) return;
      int dead = (a+k-1)%v.size();
      v.erase(v.begin()+dead);
      helper(k, v, dead);
  }
    int safePos(int n, int k) {
        // code here
        vector <int> v(n);
        iota(v.begin(), v.end(), 1);
        helper(k, v, 0);
        return v[0];
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends