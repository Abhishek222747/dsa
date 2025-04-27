Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ]
such that all the relative positions of the elements in the first array are the same as the 
elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.

Input:
N = 11 
M = 4
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {2, 1, 8, 3}
Output: 
2 2 1 1 8 8 3 5 6 7 9
Explanation: Array elements of A1[] are
sorted according to A2[]. So 2 comes first
then 1 comes, then comes 8, then finally 3
comes, now we append remaining elements in
sorted order.


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends

// User function template in C++

class Solution {
  public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
        // Your code here
        unordered_map<int,int> mp;
        for(auto i:A1){
            mp[i]++;
        }
        vector<int> ans;
        for(auto i :A2){
           while(mp[i]){
               ans.push_back(i);
               mp[i]--;
           }
        }
        sort(A1.begin(),A1.end());
        for(auto i:A1){
            if(mp[i]>0) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends