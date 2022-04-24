#include <stdio.h>

int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);

    int arr[n+1][m+1];
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) arr[i][j] = 0;

    while(p--){
        int i,st,num;
        scanf("%d%d%d",&i,&st,&num);
        for(int j=st;j<st+num;j++) arr[i][j] = 1;
    }

    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == 0) sum++;
            if(arr[i][j]==1 || j==m){
                if(ans < sum) ans = sum;
                sum = 0;
            }
        }
    }
    printf("%d",ans);
}