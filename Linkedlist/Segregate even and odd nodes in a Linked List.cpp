Given a link list, modify the list such that all the even numbers appear before all the odd 
numbers in the modified list. The order of appearance of numbers within each segregation 
should be the same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.


//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* curr= head;
        Node* prev= nullptr;
        
        //to store even nodes
        Node* resStart= nullptr;
        Node* resEnd= nullptr;
        
        //we will if data is even then store it in resStart 
        //and resEnd and skip odd ones by updating it in head
        //
        while(curr!=nullptr){
            if(curr->data %2==0){
                //remove the current even node
                if(prev!=nullptr){
                    prev->next= curr->next;
                }
                //if even node is at head
                //head here represent odd is starting
                else{
                    head= curr->next;
                }
                
                if(resStart== nullptr){
                    resStart= curr;
                    resEnd= resStart;
                }else{
                    resEnd->next= curr;
                    resEnd= resEnd->next;
                }
                
                curr= curr->next;
            }
            //odd then update prev to remove if next is even
            else{
                prev= curr;
                curr= curr->next;
            }
        }
        //if no even present return odd
        if(resStart==nullptr) return head;
        
        //else append odd stuff into even end
        resEnd->next= head;
        
        return resStart;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
