//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int t[10001][10001];

class Solution {
public:
    
    int help(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>>&v) {
        if (n == 0 || W == 0) return 0;
        if (v[W][n] != -1) return v[W][n];

        if (W < wt[n - 1]) {  
            return v[W][n] = help(W, val, wt, n - 1, v);
        } 

        return v[W][n] = max(val[n - 1] + help(W - wt[n - 1], val, wt, n - 1, v),
                              help(W, val, wt, n - 1, v));
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> t(W+1, vector<int>(n+1, -1));
        return help(W, val, wt, n, t);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends