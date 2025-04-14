Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR
subset value in the given array arr[].


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int n)
    {
        //Your code here
        int index=0;
        for(int i=31; i>=0; i--){
            int max_ele= INT_MIN,max_ind= index;
            for(int j=index; j<n; j++){
                if((arr[j] & (1<<i))!=0 && arr[j]>max_ele){
                    max_ele= arr[j];
                    max_ind= j;
                }
            }
            
            if(max_ele==INT_MIN) continue;
            
            //do this to prepare final result
            swap(arr[index], arr[max_ind]);
            max_ind= index;
            
            //remove all the set bits in other elements at this i bit
            for(int j=0; j<n; j++){
                if(j!= max_ind && (arr[j] & (1<<i))!=0){
                    //means arr[j] is set at ith bit so remove 
                    arr[j]= arr[j]^arr[max_ind];
                }
            }
            index++;
        }
        
        int res=0;
        for(index=0; index<n; index++){
            res= res^arr[index];
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends