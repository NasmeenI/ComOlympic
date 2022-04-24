#include <stdio.h>
 
int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);

    int sum = (x/3) + (y/3) + (z/3);
    x %= 3;
    y %= 3;
    z %= 3;

    int mn = x;
    if(mn > y) mn = y;
    if(mn > z) mn = z;
    printf("%d",sum + mn);
}