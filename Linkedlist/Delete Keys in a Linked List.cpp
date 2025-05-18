Given a single linked list and an integer x. Your task is to complete the function
deleteAllOccurances() which deletes all occurences of a key x present in the linked list. 
The function takes two arguments: the head of the linked list and an integer x. 
The function should returns the head of the modified linked list.

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}
int sizeofthelinkedlist(Node* head)
{
    int x=0;
    while(head!=NULL)
    {
        x++;
        head=head->next;
    }
    return x;
}


/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    cout<<sizeofthelinkedlist(head)<<endl;
    printList(head);
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends


/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node* head, int x) {
    // Your code here
    Node *curr= head, *prev= nullptr;
    while(curr!=nullptr){
        if(curr->data== x){
            //if head is x, move next directly
            if(prev==nullptr){
               head= curr->next;
            }
            else{
               prev->next= curr->next;
            }
            curr= curr->next;
        }
        else{
            //this will say head is not x and update prev
            prev= curr;
            curr= curr->next;
        }
    }
    return head;
}
