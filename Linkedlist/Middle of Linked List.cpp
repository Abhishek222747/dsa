Given the head of a linked list, the task is to find the middle. For example, the middle
 of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle.
 For example, middle of 1->2->3->4->5->6 is 4.


/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        int cnt=0;
        Node* curr= head;
        while(curr!=NULL){
            curr= curr->next;
            cnt++;
        }
        int ans= cnt/2;
        Node* move= head;
        while(ans--){
            move= move->next;
        }
        return move->data;
    }
};