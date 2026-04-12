#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int val){
        data=val;
        next=nullptr;


    }

};

class Solution{
    public:
    Node* deletetail(Node* head){
        if (head ==NULL || head -> next == NULL){
            delete head ;
            return NULL;
        }

        Node *curr=head;
        while (curr->next->next!=NULL){
            curr=curr->next;

        }
        delete curr->next;
        curr->next=NULL;
        return head
    }
    
};