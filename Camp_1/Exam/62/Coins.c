#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    int arr[n+1];
    for(int i=0;i<=n;i++) arr[i] = 0;

    while(m--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int end = b+c-1;
        if(end > n) end = n;
        for(int i=b;i<=end;i++){
            if(a == 1) arr[i] += d;
            else arr[i] -= d;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",arr[i]);
}
/*
5 10
1 1 3 5
1 2 3 2
-1 3 2 2
1 10 1 10
-1 10 1 5
*/
