#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int banknote[] = {1000 ,500 ,100 ,50 ,20 ,10 ,5 ,2 ,1};
    
    for(int i=0;i<9;i++){
        if(n >= banknote[i]){
            printf("%d ",n/banknote[i]);
            n %= banknote[i];
        }
        else printf("0 ");
    }
}