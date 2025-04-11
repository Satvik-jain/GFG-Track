//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    void if_exists(int sum, vector<int> arr, vector<vector<int>> &t){
        int n = arr.size();
        for (int i = 0; i < n+1; i++){
            t[i][0] = 1;
        }
        for (int i = 1; i < n+1; i++){
            for (int j = 0; j < sum+1; j++){
                if (j >= arr[i-1]){
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector <int> v;
        v.push_back(0);
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
        if_exists(sum, arr, t);
        for (int i = 1; i < sum+1; i++){
            if (t[n][i]){
                v.push_back(i);
            }
        }
        return sum - 2*v[(v.size()-1)/2];
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends