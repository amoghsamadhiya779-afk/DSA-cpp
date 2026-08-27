//Delete the head of DLL

#include <cstddef>
class Node {
    public:
    int data;
    Node*next;
    Node* back;
    

    public:
    Node(int data1,Node*next1,Node*back1){
        data= data1;
        next=next1;
        back=back1;

    }

    public:
    Node (int data1){
        data=data1;
        next=nullptr; 
        back=nullptr;
    }
};


class Soluition{
   public:
     Node* deleteHead(Node*head){
       if(head==NULL||head->next==NULL){
          return NULL;
       }

       Node*prev=head;
       head=head-> next;
       head->back=nullptr;
       prev->next=nullptr;
       delete prev;
       return head;
    } 
//To delete the tail of the DLL

    Node* deleteTail(Node*head){
        if(head==NULL||head->next==NULL){
            return NULL;
        }

        Node* tail = head;
        while(tail->next!=NULL){
         tail = tail->next;


        }

        Node* newtail=tail->back;
        newtail->next=nullptr;
        tail->back=nullptr;
        delete tail;
        return head;

    }
// To delete the Kth element 
   Node * removeKthele(Node*head,int k){
    if (head==NULL){
        return NULL;

    }
    int cnt =0;
    Node* Knode=head;
      while(Knode!=NULL){
        cnt++;

        if(cnt==k) break;
          Knode= Knode-> next;

       
      }
      Node*prev=Knode->back;
      Node*front =Knode ->next;

      if (prev==NULL&&front ==NULL){
        return NULL;

      }

      else if (prev==NULL){
        return deleteHead(head);
      }
      else if (front==NULL){
        return deleteTail(head);

        prev->next=front;
        prev->back= prev;
        Knode->next=nullptr;
        Knode->back =nullptr;
        delete Knode; 
        return Knode ;

      }

      }
};


  

