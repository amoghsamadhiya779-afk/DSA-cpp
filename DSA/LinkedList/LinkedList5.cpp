//Search in Linked List 

struct Node{
    int data; 
    Node* next;

    Node (int val) {
        data = val;
        next=nullptr;
    }

};

class Solution{
  public:
     bool SearchVal(Node*head, int key){
        Node *curr =head;
        while (curr != nullptr){
            if(curr->data==key){
               return true ;
            }
            else
             return false;

        }

     }
};