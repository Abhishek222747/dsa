Given a non-negative integer n. Reverse the bits of n and print the number obtained
after reversing the bits.
Note:  The actual binary representation of the number is being considered for reversing
the bits, no leading 0’s are being considered.


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++


//1st solution

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        //code here
        vector<int> v;
        while(n){
            int r=n%2;
            v.push_back(r);
            n= n/2;
        }
        reverse(v.begin(),v.end());  //we got the correct bit value of n here
        int ans=0;
        for(int i=0; i<v.size(); i++){
            ans+= pow(2,i)*v[i]; //now, calculating sum from left means revrsing the bits
        }
        return ans;
    }
};

//2nd solution
class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        //code here
        unsigned int ans=0;
        while(n){
            ans= ans*2 + (n%2);
            n= n/2;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends