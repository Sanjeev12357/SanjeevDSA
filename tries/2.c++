#include<iostream>
#include<vector>
using namespace std;



class TrieNode{
    public:
    char ch;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch){
        this->ch=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
    }

};


void insertNode(TrieNode* root,string word){
   
    if(word.length()==0){
        root->isTerminal=true;
        return ;
    }

    int ch=word[0];
    int index=ch-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){

        //it means character is already present so traverse

        child=root->children[index];
    }else{
        child=new TrieNode(ch);
       root->children[index]=child;
    }

    insertNode(child,word.substr(1));
}

bool searchNode(TrieNode *root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }

    char ch=word[0];
    int index=ch-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        return false;
    }

    return searchNode(child,word.substr(1));
}


void storeString(TrieNode* root,string prefix, string & input,vector<string> & ans){

    if(root->isTerminal==true){
        ans.push_back(prefix);
    }

    for(char i='a' ;i<='z';i++){
        int index=i-'a';
        TrieNode * next=root->children[index];
        if(next!=NULL){
            input.push_back(i);
            storeString(next,prefix+i,input,ans);
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode * root,string prefix, string input,vector<string> & ans){

    if(input.length()==0){
       
        storeString(root,prefix,input,ans);
        return ;
    }

    char ch=input[0];
    int index=ch-'a';
    TrieNode * child;
    if(root->children[index]){
        child=root->children[index];
    }else{
        return;
    }

    findPrefixString(child, prefix,input.substr(1),ans);
}

//get suggestion 
vector<vector<string >> getSuggestion(TrieNode *root,string input){

    vector<vector<string>> output;

    TrieNode *prev=root;

    string inputhelper="";
    for(int i=0;i<input.length();i++){
        char lastChar=input[i];
        int index=lastChar-'a';
        TrieNode * curr=prev->children[index];

        if(curr==NULL){
            break;
        }else{
            vector<string> ans;
            inputhelper.push_back(lastChar);
            string dummy="";
            storeString(curr,inputhelper,dummy,ans);
            output.push_back(ans);
            prev=curr;
        }
    }
    return output;
    
}

int main(){
    TrieNode *root=new TrieNode('-');
     insertNode(root, "cater");
    insertNode(root, "care");
    insertNode(root, "com");
    insertNode(root, "lover");
    insertNode(root, "loved");
    insertNode(root, "load");
    insertNode(root, "love");
    insertNode(root, "bat");
    insertNode(root, "cat");
    insertNode(root, "car");
     cout<<"hii";

    string prefix="loa";
    // vector<string> ans;
    // findPrefixString(root,prefix,prefix,ans);

    // for(auto it: ans){
    //     cout<<it<<" ";
    // }


    vector<vector<string>> ans=getSuggestion(root,prefix);

    for(int i=0;i<ans.size();i++){

        cout<<i<<"->";
        for(auto str:ans[i]){
            cout<<str<<" ";
        }
        cout<<endl;
    }
   

    // if(searchNode(root,"love")){
    //     cout<<"found";
    // }else{
    //     cout<<"not found";
    // }
}