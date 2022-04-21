#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left ,*right;
};

node* newnode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert_tree(node* root ,int data){
    if(root==NULL) root = newnode(data);
    else if(data > root->data) root->right = insert_tree(root->right ,data);
    else if(data < root->data) root->left = insert_tree(root->left ,data);

    return root;
}

node* find_min(node* root ,int data){
    if(root->left==NULL) return root;
    else find_min(root->left ,data);
}

node* find_max(node* root ,int data){
    if(root->right==NULL) return root;
    else find_max(root->right ,data);
}

node* search_tree(node* root ,int data){
    if(root==NULL) return NULL;
    else if(data == root->data) return root;
    else if(data > root->data) return search_tree(root->right ,data);
    else if(data < root->data) return search_tree(root->left ,data);
}

int inorder_successor(node* root){
    if(root->left==NULL){
        int data = root->data;
        root = NULL;
        return data;
    }
    return inorder_successor(root->left);
}

int preorder_successor(node* root){
    if(root->right==NULL){
        int data = root->data;
        root = NULL;
        return data;
    }
    return preorder_successor(root->right);
}

node* erase_node(node* root ,int data){
    root = search_tree(root ,data);
    if(root==NULL) return root;

    if(root->left == NULL and root->right == NULL) root->data = NULL;
    else if(root->left == NULL) root = root->right;
    else if(root->right == NULL) root = root->left;
    else{
         root->data = inorder_successor(root->right);
        //root->data = preorder_successor(root->left);
    }
    return root;
}

void preorder(node* root){
    if(root == NULL) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void posorder(node* root){
    if(root == NULL) return;
    posorder(root->left);
    posorder(root->right);
    cout << root->data << ' ';
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    node* root = NULL;
    for(int i=0;i<n;i++) root = insert_tree(root ,arr[i]);

    inorder(root);
}
// 5 5 3 2 4 7
