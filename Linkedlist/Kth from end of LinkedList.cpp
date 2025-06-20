Given the head of a linked list and the number k, Your task is to find the kth node
from the end. If k is more than the number of nodes, then the output should be -1.

//Solution 1

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node* curr= head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr= curr->next;
        }
        if(k>len)return -1;
        int search= len-k+1;
        Node* ele= head;
        for(int i=1; i<search; i++){
            ele= ele->next;
        }
        return ele->data;
    }
};


//Solution 2

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
       Node* main= head;
       Node* ref= head;
       for(int i=1; i<k; i++){
           ref= ref->next;
           if(ref==NULL) return -1;
       }
       while(ref->next!=NULL){
           main= main->next;
           ref= ref->next;
       }
       return main->data;
    }
};