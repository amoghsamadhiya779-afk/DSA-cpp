// Find the length of the linked list

#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data ;
    Node * next ;

    Node (int data1){
        data = data1;
        next=nullptr;
        
    }
};

class Solution {
    public:
      int lengthOfLL(Node*head){
        int count =0;

        Node*temp=head;
        while (temp!=nullptr){
            count ++;
            temp = temp->next;
        }
           return count;
      }
};