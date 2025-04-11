//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = (d + accumulate(arr.begin(), arr.end(),0));
        if (sum%2!=0) return 0;
        sum/=2;
        int n = arr.size();
        vector<vector<int>> t(n+1 , vector<int> (sum+1, 0));
        for (int i = 0; i < n+1; i++){
            t[i][0] = 1;
        }
        for (int i = 1; i < n+1; i++){
            for (int j = 0; j < sum+1; j++){
                if (j >= arr[i-1]){
                    t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends