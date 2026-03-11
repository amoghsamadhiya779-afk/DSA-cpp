#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* OOPS Object Interaction 
   Goal :Create a Library that holds multiple Book Objects.

*/

// 1. The Book Class (The Blueprint for a single book)
class Book{
    private:
     string title;
     string author;
     bool isAvailable;

    public:
    //Constructor
    Book(string t ,string a){
        title = t;
        author= a;
        isAvailable =true; //All new books start as available 

    }
    
    void displayInfo(){
        cout<<"-"<<title<<"by"<<author;
        if (isAvailable) cout<<"[Available]"<<endl;
        else cout<<"[CHECKED OUT]"<<endl;

    }

    
    // If it is available ,set isAvailable to false and print success.
    // If it is already checked out , print a failure message.
    void borrowBook(){
        if (isAvailable==false){
          cout<<"The Book is not available"<<endl;

        }
        else {
            cout<<"Success"<<endl;
            isAvailable=false;

        }

    }
    };
    //2. The Library Class (The blueprint for a collection of books)

    class Library{
        private:
        //This is a Vector (dynamic array) that holds 'Books'object!!
        vector<Book>books;
        public:
          //Method to add a new book to the library
          void addBook(string title,string author){
            Book newBook(title,author);   // Create the object 
            books.push_back(newBook);
            cout<<"Added to Library :"<<title<<endl;
          }
          // Method to show all books
          void displayAllBooks(){
            cout<<"\n Current Library Collection:"<<endl;
            // Loop through the vector of objects
              for (int i = 0; i < books.size(); i++) {
            books[i].displayInfo(); 
        }
        cout << "---------------------------" << endl;
          }

        // Write a method to borrow a book by its INDEX in the vector.  
        void CheckoutBookByIndex(int index){
        
              if (index >=0 && index<books.size()){
                books[index].borrowBook();

              }
              else{
                cout<<"Invalid Book Index!"<<endl;
              }
        }
    
               
    
    };

    int main() {
    Library myLibrary;

    myLibrary.addBook("The Pragmatic Programmer", "Andrew Hunt");
    myLibrary.addBook("Clean Code", "Robert C. Martin");
    
    myLibrary.displayAllBooks();

    
    cout << "\n--- Trying to borrow Book 0 ---" << endl;
     myLibrary.CheckoutBookByIndex(0);
    
     myLibrary.displayAllBooks();
    
     cout << "\n--- Trying to borrow Book 0 AGAIN ---" << endl;
     myLibrary.CheckoutBookByIndex(0);

    return 0;
}
