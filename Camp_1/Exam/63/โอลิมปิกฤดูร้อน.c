#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float wg,ws,wb;
    scanf("%f%f%f",&wg,&ws,&wb);

    float sum[n+1];
    for(int i=1;i<=n;i++){
        float g,s,b;
        scanf("%f%f%f",&g,&s,&b);
        sum[i] = (g*wg) + (s*ws) + (b*wb);
    }

    int num = 1;
    for(int i=2;i<=n;i++){
        if(sum[i] > sum[1]) num++;
    }
    printf("%d",num);
}