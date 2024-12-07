#include<iostream>
#include<vector>
using namespace std;

 bool isPalindrome(string str,int start,int end){
        while(start<=end){
            if(str[start++]!=str[end--]){
                return false;
            }
        }
        return true;
    }

void helper(string str,vector<string> &path,vector<vector<string>> &output, int i){

    if(i==str.size()){
        output.push_back(path);
        return ;
    }

    for(int index=i;index<str.size();index++){
        if(isPalindrome(str,i,index)){
            path.push_back(str.substr(i,index-i+1));
            helper(str,path,output,index+1);
            path.pop_back();
        }
    }
}








int main(){

    string str="nitin";
    int i=0;
    vector<string > path;
    vector<vector<string>> output;
    helper(str,path,output,i);

    for (const auto& row : output) {
        // Loop through the inner vector (each row)
        for (const auto& str : row) {
            cout << str << " ";  // Print each string followed by a space
        }
        cout << endl;  // Move to the next line after printing a row
    }
}