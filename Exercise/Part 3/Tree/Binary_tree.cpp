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

node* insert_tree(int arr[] ,node* root ,int i ,int n){
    if(i >= n) return root;
    node* temp = newnode(arr[i]);
    root = temp;

    root->left = insert_tree(arr ,root->left ,i*2+1 ,n);
    root->right = insert_tree(arr ,root->right ,i*2+2 ,n);
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
    node* root = insert_tree(arr ,root ,0 ,n);

    preorder(root); cout << endl;
    //inorder(root); cout << endl;
    posorder(root); cout << endl;
}
