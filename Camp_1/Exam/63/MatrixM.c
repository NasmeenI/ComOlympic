#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&arr[i][j]);

    for(int k=1;k<=n;k++){
        int ck = 1;
        for(int i=1;i<=n;i++){
            if(i == k) continue;
            if(arr[i][k] == 0){
                ck = 0;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(j == k) continue;
            if(arr[k][j] == 1){
                ck = 0;
                break;
            }
        }
        if(ck == 1){
            printf("%d",k);
            return 0;
        }
    }
    printf("-1");
}