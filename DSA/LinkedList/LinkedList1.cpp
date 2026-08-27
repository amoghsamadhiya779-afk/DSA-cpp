#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;


    // Creating Consturctor with data and Next

    Node(int data1 , Node*next1){
        data =data1;
        next =next1;
    }
    //Consturctor  with data null_ptr

    Node (int data1){
        data =data1;
        next=nullptr; 
    }


};

int main(){
    //create an array 
    vector <int> arr ={2,5,8,7};
    Node*y =new Node(arr[0]);
    cout<<y<<"\n";

}