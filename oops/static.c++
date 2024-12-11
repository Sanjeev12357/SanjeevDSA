#include<iostream>

using namespace std;

class abc {
    public:
    static int x, y;

    static void print ()
    {
        cout<<  x<<""<<  y<< endl;
    }
};

//st atic data memeber -> that variable is goint to ashare memory with all of the class instances

// statice memeber function there is no isnstance of that clas sbegin passed into that method

int abc::x;
int abc::y;

int main(){
    abc obj1;
    abc::print();
    obj1.x=1;
    obj1.y=2;
    abc obj2;
    obj2.x=10;
    obj2.y=20;
    obj1.print();
    obj2.print();
}


// inline function 


/// an inline function is  reguakr fucntion that is defined by the inline keyword 


// the code for an inline forfunction is inserted into the code fo the calling functuion by compiler while compiling , ehcih can reslt in faster executiona nd less over head compared toe regualr functin call 
// instead of calling function the statements of function are pasted in calling function

// used with small sized function so that execultables are small handled automaticallty by compiler optimisation levels
