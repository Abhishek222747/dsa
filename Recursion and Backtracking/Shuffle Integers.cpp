Given an array arr of n elements in the following format {a1, a2, a3, a4, ... , an/2, b1, b2, b3, b4, ... , bn/2},
the task is shuffle the array to {a1, b1, a2, b2, a3, b3, ... , an/2, bn/2} without using extra space.
Note that n is even.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    void recursion(int arr[],int start,int mid,int end){
        if(mid>=end) return;
        //here mid is 1st element of y in x1,x2..y1,y2..
        int temp= arr[mid];
        for(int i=mid; i>start+1; i--){
            arr[i]=arr[i-1];  //move each from start+1 to mid-1 right side by 1
        }
        arr[start+1]= temp;
        recursion(arr,start+2,mid+1,end);
    }
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    recursion(arr,0,n/2,n);
	}
		 

};


//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends