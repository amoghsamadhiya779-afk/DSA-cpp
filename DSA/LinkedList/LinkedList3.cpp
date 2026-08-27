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

class Solution {
public:
    // Function to delete tail node of linked list
    Node* deleteTail(Node* head) {
        // If list is empty or has one node
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the second last node
        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        // Delete tail node
        delete curr->next;
        curr->next = NULL;

        // Return updated head
        return head;
    }
};
