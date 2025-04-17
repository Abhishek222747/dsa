Given a number N. Find the length of the longest consecutive 1s in its binary representation.

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int ans=0,cnt=0;
        for(int i=0; i<=31; i++){
            int mask= 1<<i;
            if(N&mask) cnt++;
            else{
                ans= max(ans,cnt);
                cnt=0;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends