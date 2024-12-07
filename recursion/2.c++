#include<iostream>
using  namespace std;



void helper(string s,string& temp,int i){
    if(i>s.length()){
        return;
    }

    if(temp.size()==0){
        temp+=s[i];
    }

    if(temp.back()==s[i]){
        helper(s,temp,i+1);
    }else{
        temp+=s[i];
        helper(s,temp,i+1);
    }
    
}
int main (){


    string s="geeksforgeeks";
    string temp="";
    helper(s,temp,0);
    cout<<temp;
    return 0;
}