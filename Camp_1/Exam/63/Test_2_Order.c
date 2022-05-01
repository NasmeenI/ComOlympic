#include <stdio.h>
#define ll long long

int main(){
    int m;
    scanf("%d",&m);
    while(m--){
        ll a1,n,d;
        scanf("%d%d%d",&a1,&n,&d);

        ll sum = 0;
        for(int i=1;i<=n;i++){
            ll a = a1 + d*(i-1);
            while (a != 0) {
                sum += a % 10;
                a /= 10;
            }
        }
        printf("%d\n",sum);
    }
}