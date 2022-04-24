#include <stdio.h>

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    
    int p;
    scanf("%d",&p);
    int arr2[p][p];
    for(int i=0;i<p;i++) for(int j=0;j<p;j++) scanf("%d",&arr2[i][j]);
    
    for(int i=0;i<=m-p;i++){
        for(int j=0;j<=n-p;j++){
            int sum = 0;
            for(int i1=i;i1<i+p;i1++){
                for(int j1=j;j1<j+p;j1++){
                    sum += (arr[i1][j1] * arr2[i1-i][j1-j]);
                }
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
}