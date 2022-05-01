#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    int sum = 0;
    for(int i=1;i<n-1;i++){
        int left = arr[i];
        for (int j=0;j<i;j++) left = max(left, arr[j]);
         
        int right = arr[i];
        for (int j=i+1;j<n;j++) right = max(right, arr[j]);
           
        sum += min(left, right) - arr[i];  
    }
    cout << sum;
}