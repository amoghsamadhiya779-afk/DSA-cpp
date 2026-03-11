#include <iostream> 
#include <string>
using namespace std;


// 1 . The Abstract Base Class 
class Payment {
    protected:
       double amount;
    public:
       Payment (double amt) {
        amount =amt;

       }
       virtual void ProcessPayment()=0;
};

// 2. CHILD CLASS 1. UPI

class UPIPayment: public Payment{
    private:
    string upi_id;
    public:
       UPIPayment(double amt ,string id) : Payment(amt){
         upi_id=id;
       }
       void processPayment(){
        cout<<"Processing Rs."<<amount<<"via UPI ID"<<upi_id<<endl;


       }
     
};


// 2. CHILD CLASS 2.
class CreditCardPayment : public Payment{
    private:
    string card_number;
    public:
    CreditCardPayment(string card_no,double amt) :Payment(amt){
        card_number = card_no;
    }
    void ProcessPayment (){
        cout<<"Processing rs."<<amount<< "via Card no."<<card_number<<endl;
    }
};