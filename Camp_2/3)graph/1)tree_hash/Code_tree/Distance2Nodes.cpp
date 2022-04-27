#include <bits/stdc++.h>
using namespace std;

int a,b;

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

int finddis(node* root ,int x ,int cnt){
    if(x==root->data) return cnt;
    else if(x < root->data) return finddis(root->left ,x ,cnt+1);
    else if(x > root->data) return finddis(root->right ,x ,cnt+1);
}

int distance(node* root){
    if(a > root->data and b > root->data) distance(root->right);
    else if(a < root->data and b < root->data) distance(root->left);
    else{
        int a1 = 0;
        if(a < root->data) a1 = finddis(root->left ,a ,1);
        else if(a > root->data) a1 = finddis(root->right ,a ,1);

        int b1 = 0;
        if(b < root->data) b1 = finddis(root->left ,b ,1);
        else if(b > root->data) b1 = finddis(root->right ,b ,1);

        return a1+b1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n >> a >> b;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    node* root = NULL;
    for(int i=0;i<n;i++) root = insert_tree(root ,arr[i]);

    cout << distance(root);
}
