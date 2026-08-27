#include <iostream>
#include <string>
#include<vector>
using namespace std;

// 1. The Single Connection Class 

class DatabaseConnection{
 private:
 string*connection_url;
 public:
 DatabaseConnection(string url){
    connection_url= new string (url);
    cout<< " --> Created connetion to: "<<*connection_url<<endl;

 }
 ~DatabaseConnection(){
    cout<< "---> Destroyed connection to : "<<*connection_url<<endl;
    delete connection_url;
 }

};

// 2. THE CONNECTION POOL (LLD CHALLANGE)
class ConnectionPool{
    private:
    //A vector that holds POINTERS to DatabaseConnections
    vector<DatabaseConnection*>pool;

    public:
      //Constructor :Creates multiple connections and stores their pointers
      ConnectionPool(int pool_size,string base_url){
        cout<<"Initializing Connection Pool of Size "<<pool_size<<"..."<<endl;
        for(int i=0;i<pool_size;i++){
            DatabaseConnection* new_conn =new DatabaseConnection(base_url+ "_"+to_string(i+1));
            //Adding pointer back to our vector
            pool.push_back(new_conn);

        }
    }

        //Pool Destructor
        ~ConnectionPool(){
            cout<<"n Shutting down all the Connections in the Pool . Freeiing memory..."<<endl;
            for (int i=0;i<pool.size();i++){
                delete pool[i];
            }

        }
      

};