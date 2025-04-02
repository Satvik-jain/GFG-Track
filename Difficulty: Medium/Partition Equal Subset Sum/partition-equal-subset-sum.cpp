//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool knapsack(vector<int>& nums, int W, vector<vector<int>> &t, int n) {
        if (W == 0) return true;
        if (n == 0) return false;
        if (t[n][W] != -1) return t[n][W];

        if (nums[n - 1] > W) 
            return t[n][W] = knapsack(nums, W, t, n - 1);

        return t[n][W] = knapsack(nums, W, t, n - 1) || knapsack(nums, W - nums[n - 1], t, n - 1);
    }
    bool equalPartition(vector<int>& nums) {
        // code here
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int m = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        if (sum - 2*max < 0) return false;
        if (sum - 2*max == 0) return true;
        else{
            int diff = sum;
            // cout << diff/2;
            if (diff%2!=0) return false;
            else{
                vector<vector<int>>t(m+1, vector<int>(diff/2 + 1,-1));
                return knapsack(nums, diff/2, t, m);
            }
        }
        
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends