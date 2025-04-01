//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool help(vector<int>& arr, int sum, int n, vector<vector<int>> &t){
        if (t[sum][n] != -1) return t[sum][n] ;
        if (sum == 0) return t[sum][n]  = true;
        if (n==0) return t[sum][n]  = false;
        else if (arr[n-1] > sum){
            return t[sum][n] = help(arr, sum, n-1, t);
        }
        else{
            if(help(arr, sum, n-1, t)) return t[sum][n]  = true;
            if(help(arr, sum-arr[n-1], n-1, t)) return t[sum][n]  =  true;
            return t[sum][n] = false;
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> t(sum+1, vector<int>(n+1, -1));
        return help(arr, sum, n, t);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends