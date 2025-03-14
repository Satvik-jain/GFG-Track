//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
    void helper(vector<string> &v, int one, int zero, string op, int n){
        if (one + zero == n){
            v.push_back(op);
            return;
        }
        if (one == zero){
            op.push_back('1');
            helper(v, one+1, zero, op, n);
            return;
        }
        string op1 = op;
        string op2 = op;
        // if (zero < one){
            
        // }
        op2.push_back('1');
        helper(v, one+1, zero, op2, n);
        op1.push_back('0');
            helper(v, one, zero+1, op1, n);
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    int one = 0, zero = 0;
	    vector<string> v;
	    string op;
	    helper(v, one, zero, op, n);
	   // sort(v.begin(), v.end())
	    return v;
	}
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends