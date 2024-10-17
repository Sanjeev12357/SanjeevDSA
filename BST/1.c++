#include <iostream> 
#include <queue>
#include <stack>
using namespace std;

// Definition of the Node class
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert data into the BST
Node* insertIntoBst(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Insert data based on the BST property
    if (data > root->data) {
        root->right = insertIntoBst(root->right, data);
    } else {
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}

Node* minValue(Node * root){
    if(root==NULL){
        cout<<"no min value"<<endl;
        return NULL;
    }

    Node *temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}
Node * maxValue(Node * root){
    if(root==NULL){
        cout<<"no max value"<<endl;
        return NULL;
    }

    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
// Function to create the BST by taking input
void createBst(Node* &root) {
    cout << "Enter data (-1 to stop): " << endl;
    int data;
    cin >> data;

    // Keep taking input until the user inputs -1
    while (data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Function for level-order traversal (BFS) with level separation
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return; // If tree is empty, nothing to traverse
    }

    queue<Node*> q; // Queue to store nodes level by level
    q.push(root);   // Push root node into the queue
    q.push(NULL);   // Marker to indicate the end of a level

    // Process the queue
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            // End of the current level, print a new line
            cout << endl;

            // If there are more nodes in the queue, push a new NULL marker
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Print the current node's data
            cout << front->data << " ";

            // Push the left and right children (if any) into the queue
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}


Node * deleteFromBST(Node * root, int target){

    if(root==NULL){
        return NULL;
    }

    if(target==root->data){
        // ab delete kargenge

        if(root->left==NULL && root->right==NULL){
            //leaf node
            delete root;
            return NULL;
        } else if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }else{
            // left subtree ki max value 
            Node * mxi =maxValue(root->left);
            root->data=mxi->data;

            root->left=deleteFromBST(root->left,mxi->data);
            return root;
        }

    }else if(root->data>target){
        //left mai jao
        root->left= deleteFromBST(root->left,target);
    }else{
        //right mai jao
        root->right= deleteFromBST(root->right,target);
    }

    return root;
}

Node * bstFromINorder(int inorder[],int s, int e){
    //base case 
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int element=inorder[mid];
    Node* root=new Node(element);
    // baki recursion
    root->left=bstFromINorder(inorder,s,mid-1);
    root->right=bstFromINorder(inorder,mid+1,e);
    return root;
}
// Main function to create the BST and perform the level-order traversal


void converBstToDLL(Node*root,Node* &head){
    if(root==NULL){
        return;
    }

    converBstToDLL(root->right,head);

    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;

    converBstToDLL(root->left,head);
}

void printDLL(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}

Node * convertDLLtoBst(Node* & head, int n){
    if(head==NULL || n<=0){
        return NULL;
    }

    Node* lefts=convertDLLtoBst(head,n/2);

    Node* root=head;
    root->left=lefts;
    head=head->right;

    Node* rights=convertDLLtoBst(head,n-n/2-1);
    root->right=rights;

    return root;



}
  
void inorderBstusingstack(Node*root){
    stack<Node*> s;
    while(1){
        while(root){
            s.push(root);
             root=root->right;
        }
        Node *stop=s.top();
        s.pop();
        cout<<stop->data<<" ";
         root=stop->left;
      
        if(s.empty() && root==NULL){
            break;
        }

    }
}
void in(Node* root, Node*& prev){
    if(!root){
        return ;
    }
    in(root->left,prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    in(root->right,prev);
}
void din(Node* root, Node*& prev) {
    if (!root) {
        return;
    }
    // Traverse the right subtree first (for decreasing order)
    din(root->right, prev);

    // Link the current node's right to the previous node
    root->right = prev;

    // Update prev to be the current node
    prev = root;

    // Traverse the left subtree
    din(root->left, prev);
}

Node* convertbsttosortedll2(Node* root) {
    Node* prev = NULL; // This will keep track of the previous node
    din(root, prev);

    // prev will be the head of the sorted singly linked list
    return prev;
}

Node* convertbsttosortedll(Node* root){
    Node * dummy= new Node(-1);
    Node* prev=dummy;
    in(root,prev);
    prev->left=NULL;
    prev->right=NULL;
    root=dummy->right;
    return root;

}

int main() {
    Node* root = NULL;
    createBst(root);
    // cout << "Level order traversal:" << endl;
    // levelOrderTraversal(root);
    // cout<<endl;




   // inorderBstusingstack(root);
     Node* head=convertbsttosortedll2(root);
        printDLL(head);

    // Node *min=minValue(root);
    // cout<<"min value is "<<min->data<<endl;

    // Node *max=maxValue(root);
    // cout<<"max value is "<<max->data<<endl;

    // int target;
    // cout<<"Enter the target to delete"<<endl;
    // cin>>target;
    // root=deleteFromBST(root,target);
    // cout << "Level order traversal after deletion:" << endl;
    // levelOrderTraversal(root);

    // int inorder[]={1,2,3,4,5,6,7};
    // int n=7;
    // Node *root=bstFromINorder(inorder,0,n-1);
    // cout << "Level order traversal after deletion:" << endl;
    // levelOrderTraversal(root);


    // Node* root = NULL;
    // createBst(root);
    // //cout << "Level order traversal:" << endl;
    // // levelOrderTraversal(root);
    // Node * head=NULL;
    // converBstToDLL(root,head);
    // cout<<endl;
    // printDLL(head);

    // Node* newroot=convertDLLtoBst(head,7);

    
    return 0;
}
