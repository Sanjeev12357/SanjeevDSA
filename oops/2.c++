#include<iostream>
using namespace std;


class Param{
    public:
    int num;

    void operator+(Param & obj2){
        int val1=this->num;
        int val2=obj2.num;
        cout<<(val2-val1)<<endl;
    }
};

int main(){
    Param obj1,obj2;
    obj1.num=10;
    obj2.num=12;

    obj1+obj2;
}