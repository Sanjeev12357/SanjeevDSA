#include<iostream>
using namespace std;

// function overriding

class Animal{
    public :
    virtual void speak(){
        cout<<"speak"<<endl;
    }
};

class Dog :public Animal{
    public:
    void speak(){
        cout<<"Bark"<<endl;
    }
};

int main(){

    // upcasting 
    // by default parent ke object ka function pick hota hai 
    // agr child ka function pick krana hai to virtual keyword ka use karna hota hai parent class main
    
    Animal *a=new Dog;
    a->speak();
}