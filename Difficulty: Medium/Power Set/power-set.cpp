//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	    void helper(string op, vector<string> &v, string s){
	        if ((s=="")&&(op!="")){
	            v.push_back(op);
	            return;
	        }
	        if ((s=="")&&(op=="")){
	           // v.push_back(op);
	            return;
	        }
	        string o1 = op;
		    string o2 = op;
	        o1.push_back(s[0]);
	        s.erase(s.begin()+0);
	        helper(o1, v, s);
	        helper(o2, v, s);
	    }
		vector<string> AllPossibleStrings(string s){
		    string op = "";
		    vector<string> v;
		    helper(op, v, s);
		    sort(v.begin(), v.end());
		    return v;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends