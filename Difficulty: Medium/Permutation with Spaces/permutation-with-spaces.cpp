//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void helper(vector<string>&v, string s, string op){
        if (s.length()==1){
            v.push_back(op + s[0]);
            return;
        }
        string op1 = op + s[0];
        string op2 = op + s[0];
        s.erase(s.begin()+0);
        op1.insert(op1.end(), ' ');
        helper(v, s, op1);
        helper(v, s, op2);
        
    }

    vector<string> permutation(string s) {
        // Code Here
        vector <string> v;
        string op = "";
        helper(v, s, op);
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends