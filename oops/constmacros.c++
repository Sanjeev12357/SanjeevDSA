// the const key word is sued to decalare that avariable function or object is immutatble it its value cannot be chagne after intitalistaion\


#include<iostream>
using namespace std;



// like a promise const int x=10 it can not be rassigned again if  it is reassigned comiler will give compilation error

/// to simpleify the code


int mai ()
{
    const int x=5;

    // lvalue -> variables having memory location  int ax , char a
    // rvalue -> doesnot have memory location 5; int &a =b;

    //initialization can be done 
    // but we cant reassign a value
    // x=10;

    // int *p = &x;
    // *p=10;
    // cout<<x<< endl;


    // const with pointer 
    int * a=new int;
     *a=2;
     cout<< * a<< endl;
     int b=5;
     a=&b;
     cout<< *a<< endl;

}