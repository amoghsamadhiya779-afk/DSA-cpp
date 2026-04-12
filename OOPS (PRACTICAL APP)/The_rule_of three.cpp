#include <iostream>
#include <cstring>
using namespace std;

/*
OOPS LEVEL 5: THE RULE OF THREE (Deep Copying)
Goal :Prevent "Double-Free" crashes when copying objects with pointers.


*/


class SecureString{
private :
char* data; // A pointer to a character array on the Heap
int length;
public:
//1 Regular Constuctor 
SecureString(const char* str){
    length =strlen(str);
    data = new char [length+1] ;//Allocate memory
    strcpy(data,str); // Copy the characters
    cout << "  -> Constructor created :"<<data<<endl;
}

// 2. The Copy constructor 
SecureString(const SecureString& source){
    length = source.length;
    data =  new char [length+1];
    strcpy (data,source.data); 

}



};