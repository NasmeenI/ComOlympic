#include <bits/stdc++.h>
using namespace std;

int ans =- 1e9;

struct node{
    int data ,dp;
    node *left ,*right;
};

node* newnode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->dp = 0;
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

void finddp(node* root){
    if(root->left != NULL) finddp(root->left);
    if(root->right != NULL) finddp(root->right);

    int a=0 ,b=0 ,c;
    if(root->left != NULL and root->left->dp > 0) a = root->left->dp;
    if(root->right != NULL and root->right->dp > 0) b = root->right->dp;
    c = root->data;

    root->dp = max(a+c ,b+c);
    ans = max(ans ,root->dp);
    ans = max(ans ,a+b+c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    node* root = insert_tree(arr ,root ,0 ,n);

    finddp(root);
    cout << ans;
}
