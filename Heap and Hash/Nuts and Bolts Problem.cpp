Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. 
You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to
 another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt
 can only be compared with the nut to see which one is bigger/smaller.
The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int partition(char arr[],int low,int high,int pivot){
        int i=low;
        for(int j=low; j<high; j++){
            if(arr[j]<pivot){
                swap(arr[i],arr[j]);
                i++;
            }
            else if(arr[j]==pivot){
                swap(arr[j],arr[high]);
                j--;   //to check the new element that came after swap
            }
        }
        swap(arr[i],arr[high]);
        return i;
    }
    void matchpattern(char nuts[], char bolts[],int low,int high){
        
        if(low<high){
            int pivot= partition(nuts,low,high,bolts[high]);
        
            partition(bolts,low,high,nuts[pivot]);
        
            matchpattern(nuts,bolts,low,pivot-1);
            matchpattern(nuts,bolts,pivot+1,high);
        }
    }
    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        matchpattern(nuts,bolts,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends





//2nd solution hashing

class Solution {
  public:
  unordered_map<char,int> mp;

    void matchPairs(int n, char nuts[], char bolts[]) {
        // Mapping custom order
        mp['!'] = 1;
        mp['#'] = 2;
        mp['$'] = 3;
        mp['%'] = 4;
        mp['&'] = 5;
        mp['*'] = 6;
        mp['?'] = 7;
        mp['@'] = 8;
        mp['^'] = 9;

        // Sorting nuts and bolts according to the custom order
        sort(nuts, nuts + n, [this](char& a, char& b) { return mp[a] < mp[b]; });  // Using custom comparator for nuts
        sort(bolts, bolts + n, [this](char& a, char& b) { return mp[a] < mp[b]; }); // Using custom comparator for bolts
    }
};
