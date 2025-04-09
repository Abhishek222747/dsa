Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid.
A word can be matched in all 8 directions at any point. Word is said to be found in a direction
if all characters match in this direction (not in zig-zag form). The 8 directions are, 
horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple 
directions starting from the same coordinates, the list should contain the coordinates only once.




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool search2D(vector<vector<char>>&grid,string word,int i,int j){
       int n= grid.size();
       int m= grid[0].size();
       if(grid[i][j]!=word[0]) return false;
       vector<int>x= {-1,-1,-1,0,0,1,1,1};
       vector<int>y= {-1,0,1,-1,1,-1,0,1};
       int len= word.size();
       
       for(int dir=0; dir<8; dir++){
           
           int k, currX= i+x[dir], currY= j+y[dir];
           
           for( k=1; k<len; k++){
               if(currX>=n ||currX<0 || currY>=m ||currY<0) break;
               if(grid[currX][currY]!=word[k]) break;
               currX+= x[dir], currY+= y[dir];
           }
           
           if(k==len) return true;
           
       }
       return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n= grid.size();
	    int m= grid[0].size();
	    vector<vector<int>> ans;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(search2D(grid,word,i,j)){
	                ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends 