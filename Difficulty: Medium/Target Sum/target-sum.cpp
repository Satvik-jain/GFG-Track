//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& nums, int target) {
        // Your code here
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum<target || (sum+target)%2!=0) return 0;
        if (sum + target < 0) return 0;
        sum = (sum+target)/2;
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
        for(int i = 0; i < n + 1; i++){
            t[i][0] = 1;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < sum + 1; j++){
                if (j >= nums[i-1]){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
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
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends