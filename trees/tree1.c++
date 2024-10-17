#include<iostream> 
#include<queue>
#include<map>
#include<bits/stdc++.h>
using namespace std;



class Node{
    public: 
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
  
};
  Node* createTree(){
    int data;
    cout<<"Enter data";
    cin>> data;
    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);
    root->left=createTree();
    root->right=createTree();

    return root;
}

void inordereTraversal(Node* root){
    if(root==NULL){//ye va; pree hai
        return ;
    }
    cout<<root->data;
    inordereTraversal(root->left);
    inordereTraversal(root->right);


    
}

void preOrderTraversal(Node* root){
    if(root==NULL){
        return ;
    }
    preOrderTraversal(root->left);
    cout<<root->data; // ye vala inordere hai

    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root==NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data;
}



void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;  // Edge case: if tree is empty

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);  // Mark the end of the first level with nullptr

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == nullptr) {
            // End of a level
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);  // Add marker for the next level
            }
        } else {
            // Print the current node's data
            cout << front->data << " ";

            // Push left and right children if they exist
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
    }
}

int searchInOrder(int element, int inOrder[], int size){
    for(int i=0;i<size;i++){
        if(inOrder[i]==element){
            return i;
        }
    }
}

Node *constructTreeFromPreAndInorderTraversal(int preOrder[],int inOrder[],int & preIndex, int inOrderStart, int inOrderEnd, int size){
    if(preIndex>=size || inOrderStart>inOrderEnd){
        return NULL;
    }

    // 1 case mais olve karunga
    int element=preOrder[preIndex];
    preIndex++;
    Node* root=new Node(element);
    //element search krna padega
    int pos=searchInOrder(element,inOrder,size);

    root->left=constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,inOrderStart,pos-1,size);
    root->right=constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,pos+1,inOrderEnd,size);

}

void printLeftView(Node *root,int level,vector<int>&leftView){
    if(root==NULL){
        return ;
    }

    if(level==leftView.size()){
        leftView.push_back(root->data);
    }
    printLeftView(root->left,level+1,leftView);
    printLeftView(root->right,level+1,leftView);
}

void printTopView(Node *root){
    queue<pair<Node*,int>>q;
    map<int,int> Nodetoidxmp;
    q.push(make_pair(root,0));

    while(!q.empty()){
      pair<Node*,int>temp=q.front();
      q.pop();

      Node* frontNode=temp.first;
      int hd=temp.second;

      if(Nodetoidxmp.find(hd)==Nodetoidxmp.end()){
        Nodetoidxmp[hd]=frontNode->data;
      }

      if(frontNode->left!=NULL){
        q.push(make_pair(frontNode->left,hd-1));
      }

      if(frontNode->right!=NULL){
        q.push(make_pair(frontNode->right,hd+1));
      }

    }

    for(auto it:Nodetoidxmp){
        cout<<it.second;
    }
}

int main(){
   Node* root=createTree();
   printTopView(root);
   // cout<<root->data;
  //  inordereTraversal(root);

    //preOrderTraversal(root);

    //postOrderTraversal(root);
    // int preOrder[]={2,8,10,6,4,12};
    // int inOrder[]={10,8,6,2,4,12};
    // int preIndex=0;
    // Node* root=constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,0,5,6);
    // levelOrderTraversal(root);
    return 0;
}