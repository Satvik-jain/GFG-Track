//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
        for (int i = 0; i < n+1 ; i++){
            t[i][0] = 1;
        }
        for (int i = 1; i < n + 1 ; i++){
            for (int j = 0; j < sum + 1 ; j++){
                if(j >= coins[i-1]){
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
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
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends