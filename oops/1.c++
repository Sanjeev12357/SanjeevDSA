#include<iostream>
using namespace std;

class Animal{
    private:
    int weight;
    // state or properties
    public:
    int age;
    int age2;
    
    char a;

    //constructor

    Animal(){
        cout<<"Constructor called"<<endl;
    }

    // parameterized constructor
    Animal(int age){
        this->age=age;
        cout<<"Paramterized constr is called";
    }

    //copy constructor
    Animal(Animal & obj){
        this->age=obj.age;
        cout<<"I am inside coppy constructor"<<endl;

    }
    // behaviour

    void eat(){
         cout<<"eation"<<endl;
    }

    void sleep(){
         cout<<"sleep"<<endl;
    }


    void setweight(int w){
        weight=w;
    }

    void getweight(){
        cout<<"weight is"<<weight;
    }

};

int main(){
    // object creation


    // static memory allocation
//     Animal rameh;
//  rameh.age=1;
//     /// agr mai kisi object ki property ko acces krna chata hu to dot object ko use krna pdta hai
//     cout<< "age of ramesh is "<<rameh.age;


//     rameh.setweight(12);
//     rameh.getweight();

    //dynamic memory allocation

    Animal *suresh=new Animal;
    (*suresh).age=15;
    suresh->age=17;
    suresh->setweight(5);
    suresh->getweight();

    Animal a(100);
   // Animal *b=new Animal;

   Animal c=a;

   Animal animal1(c);

    //cout<< "size of empty classs id "<<sizeof(Animal)<<endl;

}