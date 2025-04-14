Given a number N. You have to check whether every bit in the binary representation of the given 
number is set or not.

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

   
class Solution{
public:
    int isBitSet(int n){
        // code here 
        
        //1st solution
        if(n==0) return false;
        while(n){
            if((n&1)==0) return false;
            n>>=1;
        }
        return true;
        
        //2nd solution
        if(n==0) return false;
        if((n&(n+1))==0) return true; //here we will assume (n+1) is 2^x
        return false;
        
        // note: 2^x= 1000 or 1 or 100 or similar
        // so 2^x-1= 0111 or 0 or 011 or similar
        // so & of both is always 0
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends