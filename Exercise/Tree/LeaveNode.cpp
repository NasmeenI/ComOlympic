#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left ,*right;;
};

node* newnode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert_tree(int arr[] ,node* root ,int i ,int n){
    if(i>=n or arr[i]==-1) return root;
    node* temp = newnode(arr[i]);
    root = temp;

    root->left = insert_tree(arr ,root->left ,i*2+1 ,n);
    root->right = insert_tree(arr ,root->right ,i*2+2 ,n);
    return root;

}

void leavenode(node* root){
    if(root->left == NULL and root->right == NULL){
        cout << root->data << ' ';
        return ;
    }

    if(root->left != NULL) leavenode(root->left);
    if(root->right != NULL) leavenode(root->right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    node* root = insert_tree(arr ,root ,0 ,n);

    leavenode(root);
}
