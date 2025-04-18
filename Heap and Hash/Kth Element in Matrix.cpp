Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.


//1st Solution

//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    
cout << "~" << "\n";
}
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

int countsmallerEqual(int mat[MAX][MAX],int n,int mid){
  int count=0;
  int row= 0;
  int col= n-1;
  
  while(row<n && col>=0){
      if(mat[row][col]<=mid){
          count+= col+1;
          row++;
      }else{
          col--;
      }
  }
  return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low= mat[0][0];
  int high= mat[n-1][n-1];
  int ans=0;
  while(low<=high){
    int mid= low+(high-low)/2;
    int count= countsmallerEqual(mat,n,mid);
    
    if(count<k){
        low= mid+1;
    }else{
        ans= mid;
        high= mid-1;
    }
  }
  return ans;
}



//2nd Solution




int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  // Min-heap: (value, row, col)
    typedef tuple<int, int, int> T;
    priority_queue<T, vector<T>, greater<T>> minHeap;

    // Push first element of each column from row 0
    for (int j = 0; j < n; j++) {
        minHeap.push(make_tuple(mat[0][j], 0, j));
    }

    int result = -1;

    while (k--) {
        T current = minHeap.top();
        minHeap.pop();

        int val = get<0>(current);
        int i = get<1>(current);
        int j = get<2>(current);

        result = val;

        if (i + 1 < n) {
            minHeap.push(make_tuple(mat[i + 1][j], i + 1, j));
        }
    }

    return result;
}