#include<iostream>
using namespace std;


// friend keyword in c_+ that is used to share the information of a class that was previopusly hidden 

// for example thae private members of a class are hidden form every other calss anda cannot be modifed except rthrguh getter or setter similaryl the protected memebers are hidden forom all classes than its children classes


class A{
    private:
    int x;
    public:
    A(int _val): x(_val){};

    int getX() const {return x;}
    void setX(int _val){x=_val;}

    friend class B;
};



class B{
    public:
    void print (const A&a){
       // cout<< a.getX()<<endl;
       cout<< a.x<<endl;
    }
};


int main(){
    A a(5);
    B b;
    b.print(a);
}