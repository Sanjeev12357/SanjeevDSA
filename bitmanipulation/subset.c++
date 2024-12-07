#include<iostream>
using namespace std;


int main (){

    int a[5];
    for(int i=0;i<5;i++)
    cin>>a[i];


    for(int i=0;i<(1<<5);i++){ // 1>>5 2^5-1
        for(int j=0;j<5;j++){
            if((i>>j)&1){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
}