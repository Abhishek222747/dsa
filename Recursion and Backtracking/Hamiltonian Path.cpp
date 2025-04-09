Given an undirected graph with n vertices and m edges, your task is to determine if a Hamiltonian 
path exists in the graph.

A Hamiltonian path is a path in an undirected graph that visits each vertex exactly once.

You are provided the following:

n: The number of vertices in the graph.
m: The number of edges in the graph.
edges[][]: A 2D list where each element edges[i] represents an edge between two 
vertices edges[i][0] and edges[i][1]. 




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool dfs(int node,map<int,vector<int>>& graph,vector<int>& visited,int total_node,int count){
        visited[node]= true;
        if(count==total_node) return true;
        
        for(auto child: graph[node]){
            if(!visited[child]){
                if(dfs(child,graph,visited,total_node,count+1)) return true;
            }
        }
        visited[node]= false;
        return false;
    }
  public:
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        map<int,vector<int>> graph;
        for(int i=0; i<m; i++){
            int a= edges[i][0];
            int b= edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1; i<=n; i++){
            vector<int> visited(n+1,0);
            if(dfs(i,graph,visited,n,1)) return true;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution obj;
        if (obj.check(n, m, edges)) {
            cout << "1" << endl;
        } else
            cout << "0" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends