/*🧩 The Theory: The Decorator Pattern (Composition over Inheritance)
The FAANG rule is: Favor Composition over Inheritance.

Instead of creating a new class for every possible combination of features, the 
Decorator Pattern acts like a Russian Nesting Doll. You create a base object,
 and then you "wrap" it inside other objects that add new behaviors dynamically at runtime.*/




/*💻 The C++ Architecture
Here is how a Senior Engineer writes this system. Notice how we use the std::unique_ptr we established earlier so we don't leak memory.

1. The Core Interface
Every layer of the nesting doll must look the same to the client. */

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// The Abstract Component

class IAudioStream {
    public:
       virtual string play()=0;
       virtual ~IAudioStream()=default;
};

/*2. The Base Component  
 This is the raw , untouched object
  at the very center of nesting doll  */

class BaseStream:public IAudioStream{
    private:
       string trackName;
    public:
       BaseStream(string track):trackName(track){}
       string play() override{
        return "Straming ["+trackName+"] at 128kbps";
       }
};
/* 3. The Base Decorator 
 This is the magic . It Implements IAudioStream, but also holds a 
 pointer to an IAudioStream. It simply passes the request
 down the chain.*/

 class StreamDecorator:public IAudioStream{
    protected:
      unique_ptr <IAudioStream> wrappee; //The object wrapped inside this one
    public: 
      StreamDecorator(unique_ptr<IAudioStream>inner) : wrappee(move(inner)){}
       
      string play() override{
        return wrappee -> play(); //Delegate the work to the inner object.

      }

};

/* 4. The Concrete Decorators(The Features)
Now we add specific features . They call the inner object's play() 
method , and then append their own modifications.*/

class HighResAudio: public StreamDecorator{
    public:
      HighResAudio(unique_ptr<IAudioStream>inner) : StreamDecorator(move(inner)){}

      string play() override{
        return StreamDecorator ::play() + " -> [Upgrade to 320kbps FLAC]";


      
    }
};

class SpatialAudio : public StreamDecorator{
    public:
     SpatialAudio(unique_ptr<IAudioStream>inner) : StreamDecorator(move(inner)){}

     string play() override{
        return StreamDecorator::play() + "-> [Applied 3D Surround Sound]";
     }
};

/* 5. The Execution (The Client Code) 
Watch how beautifull we can stack these features at the runtime 
without creating a single combination class.*/
int main(){
    // 1. A free user listening to DUA LIPA
    unique_ptr<IAudioStream> myStream = make_unique <BaseStream> ("No Lie");
    cout<< myStream->play()<<endl;
    // 2. the user upgrades to Premium (High-Res)
    myStream=make_unique<HighResAudio>(move(myStream));
    cout<<myStream->play()<<endl;
    // 3 . The user puts on APPLE Airpods Pro (Spatial Audio)
    myStream =make_unique<SpatialAudio>(move(myStream));
    cout<<myStream->play()<<endl;

    return 0;

}


