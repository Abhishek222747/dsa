Given a data stream arr[] where integers are read sequentially, the task is to 
determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the
 median will be the arithmetic mean of the two middle values.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> leftmaxheap;
        priority_queue<int,vector<int>,greater<int>> rightminheap;
        vector<double> ans;
        for(int i=0; i<arr.size(); i++){
            //this will give max elemt in the left half
            leftmaxheap.push(arr[i]);
            
            //push the max from left half into rightminheap or large right half
            int temp= leftmaxheap.top();
            leftmaxheap.pop();
            rightminheap.push(temp);
            
            //if this is the case then pop min and put into left small half 
            if(rightminheap.size()>leftmaxheap.size()){
                int temp= rightminheap.top();
                rightminheap.pop();
                leftmaxheap.push(temp);
            }
            
            double m;
            if(leftmaxheap.size()==rightminheap.size()){
                m= double(leftmaxheap.top()+rightminheap.top())/2;
            }else{
                m= leftmaxheap.top();
            }
            ans.push_back(m);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends