// Creation of doubly linked list 

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    
    
    public:
    Node (int data1,Node* prev1,Node*next1){
        data =data1;
        prev=prev1;
        next=next1;


    }
    public:
    Node (int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
};