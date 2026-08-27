#include <iostream>
#include <string>
using namespace std;

/*
==============================================
OOPs LLD : The Singleton Pattern 
Goal to ensure only ONE Database instance can ever exist.
==============================================
*/

class Database {
    private:
    static Database* instance;

    int connection_id;

    Database(){
        connection_id=1045; //Arbitrary id
        cout<< "[Expensive Operation] Establishing connection to AWS RDS Database..."<<endl;
    


    }
    public:
     
    static Database* getInstance(){
        if (instance ==nullptr){
            instance = new Database();
        }
        return instance;
    }

    void query (string sql){
        cout<<"   -> Executing: "<<sql<<"[Using  Connection ID:]"<<connection_id<<"]"<<endl;

    }
    // Quick helper to check memory address
    void printAddress() {
        cout << "   -> Object Address: " << this << endl;
    }
};

// Initialize the static pointer to NULL outside the class (Required in C++)
Database* Database::instance = nullptr;

// ==========================================
int main() {
    cout << "--- Microservice Booting Up ---" << endl;

    // ERROR: You cannot do this anymore! The constructor is private.
    // Database db1; 

    cout << "\n[Module A - User Login] Requesting Database Access..." << endl;
    // TASK 2: Call Database::getInstance() and store it in a pointer called 'db1'
    Database* db1 = Database::getInstance();
    db1->query("SELECT * FROM Users WHERE id = 1");
    db1->printAddress();

    cout << "\n[Module B - Payment Gateway] Requesting Database Access..." << endl;
    // TASK 3: Call Database::getInstance() and store it in a pointer called 'db2'
    Database* db2 = Database::getInstance();
    db2->query("INSERT INTO Orders (amount) VALUES (500)");
    db2->printAddress();
    
    // FAANG CHECK:
    // If successful, the "EXPENSIVE OPERATION" message should only print ONCE!
    // Both db1 and db2 will point to the exact same memory address.

    return 0;
};

