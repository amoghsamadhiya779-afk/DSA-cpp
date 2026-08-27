#include<iostream>
#include<string>
using namespace std;
// 1. The Abstract Base Class (The Blueprint)
class PaymentMethod{
    public:
     virtual void processPayment(double amount)=0;//Pure virtual function
     virtual ~PaymentMethod(){}     
};

// 2. Concrete Class A
class UPI: public PaymentMethod{
    public: 
      void processPayment(double amount) override{
        cout<< "Processing $"<<amount<<"via UPI (Google Pay)... Success"<<endl;
      }

};

// 3. Concrete Class B
class CreditCard: public PaymentMethod{
  public:
    void processPayment(double amount) override{
        cout<<"Processing "<<amount<<"via Credit Card(Visa)...Success!"<<endl;

    }
}; 


// THE FACTORY

class PaymentFactory{
    public:
  
  
    // This is the manufacturing line .It takes a string and returns a Pointer to the Base Class.

   static PaymentMethod* createPayment(string type){
     if (type == "UPI"){
        return new UPI();
     }
     else if (type == "Credit Card") return new CreditCard();
        } 
     else {
            cout << "❌ Error: Invalid payment method selected." << endl;
            return nullptr;
        }
    
};

// =====================================================================
int main() {
    cout << "--- Amazon Checkout System ---" << endl;
    double cart_total = 299.99;
    
    // Notice how clean the main code is! 
    // We don't use 'new UPI()' or 'new CreditCard()' here at all.
    
    cout << "\n[User selects UPI]" << endl;
    PaymentMethod* payment1 = PaymentFactory::createPayment("UPI");
    if (payment1) {
        payment1->processPayment(cart_total);
        delete payment1; // Clean up memory to prevent leaks
    }

    cout << "\n[User selects Credit Card]" << endl;
    PaymentMethod* payment2 = PaymentFactory::createPayment("Card");
    if (payment2) {
        payment2->processPayment(cart_total);
        delete payment2;
    }
    
    cout << "\n[User selects Crypto (Not supported yet)]" << endl;
    PaymentMethod* payment3 = PaymentFactory::createPayment("Crypto");
    if (payment3) {
        payment3->processPayment(cart_total);
        delete payment3;
    }

    return 0;


    
   
};