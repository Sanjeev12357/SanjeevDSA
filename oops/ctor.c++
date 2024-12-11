/// can construct be made private
// yes it can be

//application


// singleton class


#include<iostream>
using namespace std;


class Box{
    int width;
    Box(int _w) :width(_w){};

    public:
    int getWidth(){
        return width;
    }

    void setWidth(int _w){
        width=_w;
    }

    friend class BoxFactory;


};


class BoxFactory{
    int count;

    public:
    Box getBox(int _w){
        count++;
        return Box(_w);
    }
};


int main(){
    BoxFactory bf;
    Box b=bf.getBox(10);
    cout<<b.getWidth()<<endl;
}