/* Binary Tree Traversal */
#include <iostream>
using namespace std;

int n = 15;

typedef struct node *treePointer;
typedef struct node{
    int data;
    treePointer leftChild, rightChild;
}node;

// Preorder traversal
void preorder(treePointer ptr){
    if(ptr){
        cout<<ptr->data<<" ";
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// Inorder traversal
void inorder(treePointer ptr){
    if(ptr){
        cout<<ptr->data<<" ";
        inorder(ptr->leftChild);
        inorder(ptr->rightChild);
    }
}

// Postorder traversal
void postorder(treePointer ptr){
    if(ptr){
        cout<<ptr->data<<" ";
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
    }
}


int main(){
    node nodes[n+1];
    for(int i = 1; i<=n; i++){
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for(int i = 1; i<=n; i++){
        if(i%2==0){
            nodes[i/2].leftChild = &nodes[i];
        } else {
            nodes[i/2].rightChild = &nodes[i];
        }
    }

    cout<<"***Preorder Traversal***"<<endl;
    preorder(&nodes[1]);
    cout<<"\n";

    cout<<"***Inorder Traversal***"<<endl;
    inorder(&nodes[1]);
    cout<<"\n";

    cout<<"***Postorder Traversal***"<<endl;
    postorder(&nodes[1]);
    cout<<"\n";

    return 0;

}