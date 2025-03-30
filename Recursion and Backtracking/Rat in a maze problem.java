Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at
position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1),
 under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent 
cells that are within the bounds of the matrix and not blocked.

Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, 
when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists and the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", 
These are returned in lexicographically sorted order.
Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1













//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases
        sc.nextLine();        // Consume the newline character

        while (t-- > 0) {
            String input = sc.nextLine();

            // Replace ][ with ],[
            input = input.replace("][", "],[");

            ArrayList<ArrayList<Integer>> mat = new ArrayList<>();
            String[] rows = input.split("],\\s*\\[");

            for (String row : rows) {
                row = row.replaceAll("[\\[\\]]", ""); // Remove any surrounding brackets
                ArrayList<Integer> intRow = new ArrayList<>();
                for (String num : row.split(",")) {
                    intRow.add(Integer.parseInt(num.trim()));
                }
                mat.add(intRow);
            }

            Solution obj = new Solution();
            ArrayList<String> result = obj.findPath(mat);

            if (result.isEmpty()) {
                System.out.println("[]");
            } else {
                for (String res : result) {
                    System.out.print(res + " ");
                }
                System.out.println();
            }
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    
    private static final String direction= "DLRU";
    private static final int dr[]= {+1,0,0,-1};
    private static final int dc[]= {0,-1,+1,0};
    // Function to find all possible paths
    static boolean isValid(int n,int newr,int newc,ArrayList<ArrayList<Integer>> mat){
        return newr>=0 && newr<n && newc>=0 && newc<n && mat.get(newr).get(newc)==1;
    }
    static void findallpath(int row,int col,ArrayList<ArrayList<Integer>> mat,int n,
    ArrayList<String> res,StringBuilder currentpath){
        
        if(row==n-1 && col==n-1){
            res.add(currentpath.toString());
            return;
        }
        mat.get(row).set(col,0); //visited or say blocked
        for(int i=0; i<4; i++){
            int newr= row+dr[i];
            int newc= col+dc[i];
            if(isValid(n,newr,newc,mat)){
                currentpath.append(direction.charAt(i));
                findallpath(newr,newc,mat,n,res,currentpath);
                currentpath.deleteCharAt(currentpath.length()-1);
            }
        }
        mat.get(row).set(col,1);
    }
    public ArrayList<String> findPath(ArrayList<ArrayList<Integer>> mat) {
        // code here
        int n= mat.size();
        ArrayList<String> res= new ArrayList();
        StringBuilder currentpath= new StringBuilder();
        if(mat.get(0).get(0)!=0 && mat.get(n-1).get(n-1)!=0){
          findallpath(0,0,mat,n,res,currentpath);
        }
        return res;
    }
}