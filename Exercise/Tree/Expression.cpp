#include <bits/stdc++.h>
using namespace std;

struct node{
    int data1;
    char data2;
    node *left ,*right;;
};

node* newnode(int data1 ,char data2 ,int st){
    node* temp = (node*)malloc(sizeof(node));
    temp->data1 = -1;
    temp->data2 = '#';
    if(st==1) temp->data1 = data1;
    else if(st==2) temp->data2 = data2;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert_tree(int arr1[] ,char arr2[] ,node* root ,int i ,int n){
    if(i>=n) return root;
    if(arr2[i]=='#') return root;

    node* temp;
    if(arr2[i]=='.') temp = newnode(arr1[i] ,arr2[i] ,1);
    else temp = newnode(arr1[i] ,arr2[i] ,2);
    root = temp;

    root->left = insert_tree(arr1 ,arr2 ,root->left ,i*2+1 ,n);
    root->right = insert_tree(arr1 ,arr2 ,root->right ,i*2+2 ,n);
    return root;

}

int expression(node* root){
    if(root->left == NULL and root->right == NULL) return root->data1;

    int a = expression(root->left);
    int b = expression(root->right);
    int c;
    if(root->data2=='+') c = a+b;
    else if(root->data2=='-') c = a-b;
    else if(root->data2=='*') c = a*b;
    else if(root->data2=='/') c = a/b;
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int arr1[n];
    char arr2[n];
    for(int i=0;i<=n;i++) arr1[i] = 0 ,arr2[i] = '.';
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s[0]=='-' and s[1]=='1') arr2[i] = '#';
        else if(s.size() > 1) arr1[i] = stoi(s);
        else if(s[0]>='0' and s[0]<='9') arr1[i] = stoi(s);
        else arr2[i] = s[0];
    }
    node* root = insert_tree(arr1 ,arr2 ,root ,0 ,n);
    cout << expression(root);
}
