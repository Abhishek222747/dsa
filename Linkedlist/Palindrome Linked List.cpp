Given a head singly linked list of positive integers. The task is to check if the given 
linked list is palindrome or not.

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  private: 
    Node* reverse(Node* head){
        Node* prev= NULL;
        Node* curr= head;
        Node* next;
        while(curr!=NULL){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
    
    bool isSame(Node* head, Node* head2){
        while(head && head2){
            if(head->data!= head2->data){
                return false;
            }
            else{
                head= head->next;
                head2= head2->next;
            }
        }
        return true;
    }
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if(!head || !head->next) return true;
        Node* slow= head;
        Node* fast= head;
        
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        Node* head2= reverse(slow->next);
        slow->next= NULL;
        
        bool res= isSame(head,head2);
        
        head2= reverse(head2);
        slow->next= head2;
        
        return res;
    }
};