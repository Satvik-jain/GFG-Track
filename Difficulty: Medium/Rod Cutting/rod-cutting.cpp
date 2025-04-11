//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int W = n;
        vector<int> len;
        for (int i = 1; i <= n; i++){
            len.push_back(i);
        }
        vector <vector<int>>t(n+1, vector<int>(W+1, 0));
        for (int i = 1; i < n+1; i++){
            for (int j = 0; j < W+1; j++){
                if (j >= len[i-1]){
                    t[i][j] = max(price[i-1]+t[i][j-len[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j]  = t[i-1][j]; 
                }
            }
        }return t[n][W];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends