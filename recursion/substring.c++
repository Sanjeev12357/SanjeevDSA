#include<iostream>
#include<vector>
using namespace std;


void helper(string s, int index, string temp, vector<string> & ans){
    if(index==s.size()){
        ans.push_back(temp);
        return ;
    }

    for(int i=index;i<s.size();i++){
        temp+=s[i];
        helper(s,i+1,temp,ans);
        temp.pop_back();
    }
    ans.push_back(temp);
}
int main(){
    string s="abc";
    vector<string> ans;
    string temp="";
    helper(s,0,temp,ans);
    for(auto i:ans){
        cout<<i<<endl;
    }
}