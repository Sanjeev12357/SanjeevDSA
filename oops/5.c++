#include<iostream>
using namespace std;


// the const key word is sued to decalare that avariable function or object is immutatble it its value cannot be chagne after intitalistaion\


// like a promise const int x=10 it can not be rassigned again if  it is reassigned comiler will give compilation error

/// to simpleify the code

class abc{

    // initialization list

 

    mutable int x;
    int *y;
    public:
    // abc(){
    //     x=0;
    //     y=new int (0);
    // }
       abc (int _x,int _y,int _z=0) :x(_x),y(new int(_y)){}
    // agr method ko const bana diya to ab ye kisi bhi variable ko modify nhi krskta

    int getX() const
    {
        return x;
    }

    int setX(int _val){
        x=_val;
    }

    int getY(){
        return *y;
    }

    void setY(int _val){
        *y=_val;
    }
};

int main ()
{
    abc a(1,2,3);
    cout<<a.getX()<<endl;
    const int x=5;

    // lvalue -> variables having memory location  int ax , char a
    // rvalue -> doesnot have memory location 5; int &a =b;

    //initialization can be done 
    // but we cant reassign a value
    // x=10;

    // int *p = &x;
    // *p=10;
    // cout<<x<< endl;


    // // const with pointer 
    // const  int * a=new int(2); // const data , non const pointe
    // int const *c=new int(2); // same as the above line

    //  // * a =20  cant change the content of the pointer 
    //  cout<< * a<< endl;
    //  delete a;
    //  int b=5;
    //  a=&b; // pointer itslef can be reassigned
    //  cout<< *a<< endl;


    //  // const pointer , but no const data
    //  int * const d= new int(2);
    //  *d=20 ; // chal jayega 

    // // const pointer with const data
    // const int * const e= new int (10);
    // // kuch bhi modify nhi hoskta na data na pointer

    


     // you can decalare a fucntion as const which mean that it does not modify the satae of the object it is called on



/// Macros 
//ini c++ macros are preprocesor diretives that allow yu to define constans function or code snippets that can be used thoruout your code they are typically define using the define directive and are ealuate by the preprocessor before the code is completed




}