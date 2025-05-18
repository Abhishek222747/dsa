You are given the head of a singly linked list. Your task is to determine if the linked list
contains a loop. A loop exists in a linked list if the next pointer of the last node points to
any other node in the list (including itself), rather than being null.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node
to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        //1st solution
        unordered_set<Node*> st;
        while(head!=nullptr){
            if(st.find(head)!= st.end()) return true;
            
            st.insert(head);
            
            head= head->next;
        }
        return false;
        
        
        //2nd solution
        Node* slow= head, *fast= head;
        while(slow && fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head))
            cout << "true\n";
        else
            cout << "false\n";

        // Free the allocated memory
        unordered_set<Node*> visited;
        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}

// } Driver Code Ends