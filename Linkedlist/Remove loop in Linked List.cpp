Given the head of a linked list that may contain a loop.  A loop means that the last node
of the linked list is connected back to a node in the same list. The task is to remove 
the loop from the linked list (if it exists).

Custom Input format:

A head of a singly linked list and a pos (1-based index) which denotes the position of the 
node to which the last node points to. If pos = 0, it means the last node points to null, 
indicating there is no loop.

The generated output will be true if there is no loop in list and other nodes in the list
 remain unchanged, otherwise, false.


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow= head;
        Node* fast= head;
        Node* meetingpoint= NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            
            if(slow==fast){
                meetingpoint= slow;
                break;
            }
        }
        
        if(meetingpoint==NULL) return;
        
        //find the first node of loop
        Node* start= head;
        while(start!=fast){
           start= start->next;
           fast= fast->next;
        }
        
        //start looping from start of loop and make end null
        Node* curr= start;
        while(curr->next!=start){
            curr= curr->next;
        }
        curr->next= NULL;
    }
};