#include <iostream>
#include <string>
using namespace std;

/*
=============================================================
OOPS LEVEL:4 C++ MEMORY MASTERY
GOAL : Understand 'new','delete',and the Destructor (~).
=============================================================

*/

class DatabaseConnection{
private:
  // This is a Pointer . It points to an address in the RAM (the Heap).

  string* connection_url;
public:
  // 1 . THE CONSTRUCTOR (Birth)
   DatabaseConnection(string url){
    //'new' is used to mannually carve out space in the RAM for this string.
    connection_url = new string(url);
    cout<< "[Connected] Memory allocated for:"<<*connection_url<<endl;
   }  

   // 2. Destructor (Death) 
   //Notice the tidle(~).This runs automatically when the object is destroyed.
   ~DatabaseConnection()
   {
    cout<< "[Disconnected] Memory freed "<<*connection_url<<endl;
    delete connection_url;
   

   }
};