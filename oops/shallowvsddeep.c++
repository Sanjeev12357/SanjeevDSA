#include<iostream>

using namespace std;

// global varibale is accesed using ::


class abc{
    public:
    int x;
    int *y;

    abc(int _x,int _y):x(_x),y(new int(_y)){}


    // defaut dumb copy constructor it does shallow copy
    
    abc (const abc & obj){
        x=obj.x;
        y=obj.y;
    }

    // our smart deep copy
    // abc (const abc & obj){
    //     x=obj.x;
    //     y= new int (*obj.y);
    // }
    void print () const
    {
       cout << "x: " << x << endl;        // Print value of x
        cout << "Address of y: " << y << endl; // Print memory address of y
        cout << "Value at y: " << *y << endl; 
    }

    ~abc(){
        delete y;
    }
};

int main(){

    abc *a= new abc(1,2);
    abc b=*a;
    delete a;
    b.print();
    
    // abc a(1,2);
    // a.print();

    // //abc b(a); // yaha pr call krta hai copy constructor jisme addres bhi same rhta hia pointer ka 

    // abc b=a;
    // b.print();

    // *b.y=20;
    // b.print();
    // a.print();

}