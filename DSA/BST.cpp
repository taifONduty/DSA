#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right; 
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

Node* searchBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    //data > key
    if(root->data > key){
        return searchBST(root->left, key);
    }
    //data < key
    return searchBST(root->right, key);
}

Node* deleteInBST(Node* root, int key){
    if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }else if(key > root->data){
        root->right = deleteInBST(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){

    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 6);
    insertBST(root, 8);
    insertBST(root, 9);
    insertBST(root, 10);
    deleteInBST(root, 2);

    if(searchBST(root, 10) == NULL){
        cout << "Key doesn't exist\n";
    }else{
        cout << "Key exists\n";
    }

    inorder(root);
    return 0; 

}