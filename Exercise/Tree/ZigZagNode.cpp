#include <bits/stdc++.h>
#define N 10
using namespace std;

int Lvl[N] ,Lvr[N],mx;

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

node* insertnode(int arr[] ,node* root ,int i ,int n){
    if(i>=n or arr[i]==-1) return root;
    node* temp = newnode(arr[i]);
    root = temp;

    root->left = insertnode(arr ,root->left ,i*2+1 ,n);
    root->right = insertnode(arr ,root->right ,i*2+2 ,n);
    return root;
}

void getLv(node* root ,int lv ,int st){
    if(st==1){
        if(Lvl[lv]==0) Lvl[lv] = root->data;
        if(root->left!=NULL) getLv(root->left ,lv+1 ,1);
        if(root->right!=NULL) getLv(root->right ,lv+1 ,1);
    }
    else if(st==2){
        if(Lvr[lv]==0) Lvr[lv] = root->data;
        if(root->right!=NULL) getLv(root->right ,lv+1 ,2);
        if(root->left!=NULL) getLv(root->left ,lv+1 ,2);
    }
    if(mx<lv) mx=lv;
}

void print(node* root){
    if(root==NULL) return;
    cout<<root->data<<' ';
    print(root->left);
    print(root->right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int m = 5;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    node* root = insertnode(arr ,root ,0 ,n);

    getLv(root ,0 ,1);
    getLv(root ,0 ,2);

    cout << root->data << ' ';
    for(int i=1;i<=mx;i++){
        if(i&1) cout << Lvl[i] << ' ';
        else cout << Lvr[i] << ' ';
    }
}