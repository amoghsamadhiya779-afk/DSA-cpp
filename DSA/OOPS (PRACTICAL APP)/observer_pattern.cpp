#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// ===========================================
//  1. THE INTERFACES (The Contract)
// ===========================================

// The Subscriber Interface (Anyone who wants to listen must implement this)
class IObserver{
    public:
    //FAANG: Detail: Always use virtual destructor in interfaces to prevent memeory leaks
    virtual ~IObserver()=default;
    virtual void update(const string& message) = 0;

};


// The Publisher Interface (Anyone generating events must implement this )

class ISubject {
    public:
      virtual ~ISubject() = default;
      virtual void attach(IObserver* observer) = 0 ;
      virtual void detach (IObserver* observer) = 0 ;
      virtual void notify(const string & message)=0 ;

    };

// ================================================
// 2. THE CONCRETE OBSERVER (The Listeners)
class UserApp : public IObserver{
    public:
      void update (const string& message) override {
        cout<< "[User App UI] Updating screen:" << message << "\n";


      }
      
};

class DispatchSystem : public IObserver {
    public:
       void update(const string& message) override{
        cout<< "[Dispatch System]  Removing driver from available pool. Reason:"<<message <<"\n";

       }
};

class AnalyticsEngine : public IObserver{
    public :
      void update (const string& message) override {
        cout<< "[Data Anakytics] logging event to data lake. Payload :"<<message<<"\n";
      }

};

//========================================
// 3. THE CONCRETE SUBJECT (THE EVENT GENERATOR)
//========================================

class UberDriver : public ISubject {
    private:
    // This is the core of the pattern : A list of pointers to the interface, NOT the concrete classes!
    vector<IObserver*> observers;
    string driverName;
    public:
       UberDriver (string name) : driverName(name){}

       //Subscribe
       void attach (IObserver* observer) override{
        observers.push_back(observer);
       }
      // Unsubscribe
      void detach (IObserver* observer) override{
        observers.erase(remove(observers.begin(),observers.end(),observer),observers.end());
      }
      // Broadcast the event to everyone in the list
      void notify(const string& message) override {
        for (IObserver* obs:observers){
            obs->update(message);
        }
      } 

      // ---Core Business logic---
      void acceptRide(){
        cout<<"\n>>> Driver"<<driverName<<"clicked 'ACCEPT RIDE'<<< \n";

      }
      //Instead of calling UserApp.update() manually , we just notify the list!!

};


int main(){
    //1 . Create the Publisher 
    UberDriver driverAmogh("Amogh");
    // 2. Create the Subscribes
    UserApp app;
    DispatchSystem dispatch;
    AnalyticsEngine analytics;
    //3. Wire them together (This is usually done by a Dependency Injection framework in production)
    driverAmogh.attach(&app);
    driverAmogh.attach(&dispatch);
    driverAmogh.attach(&analytics);
    //4 . Trigger the event !
    // Notice how clean this is . The driver just accepts the ride.
    // The pattern handles the routing to the 3 different system automatically.
    driverAmogh.acceptRide();
    //Imagine the Anallytics server goes down . We just detach it . The rest of the app survives!
    cout<<"\n[System] Analytics Engine went offline . Detaching .....\n";
    driverAmogh.detach(&analytics);
    driverAmogh.acceptRide();
    return 0;
}
