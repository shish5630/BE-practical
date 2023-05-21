// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    Node *left;
    Node *right;
    int data ;
};

Node *insert(Node *root ,int data ){
    if(!root){
        root = new Node;
        root->left = NULL;
        root->right  = NULL;
        root->data  = data;
        return root;
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left = new Node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right = new Node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        }
        else{
            q.push(temp->right);
        }
    }
}
void bfs(Node *head){
    queue<Node *>q;
    q.push(head);
    int qSize;
    while(!q.empty()){
        qSize = q.size();
        #pragma omp parallel for
        for(int i =0;i<qSize;i++){
            Node *curr;
            #pragma omp critical
            {
                curr = q.front();
                q.pop();
                cout<<"parents node "<<curr->data<<endl;
            }
            #pragma omp critical 
            {
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right !=NULL){
                    q.push(curr->right);
                }
            }
        }
        
    }
}

int main() {
    Node *root = NULL;
    int data ;
    char ans;
    do{
        cout<<"Enter the data ";
        cin>>data;
        root = insert(root,data);
        cout<<"wants to enter more item ";
        cin>>ans;
        
    }while(ans =='Y'|| ans == 'y');
    bfs(root);
    return 0;
}
