#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float arr[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    
    float sum_all = 0;
    for(int i=1;i<=n;i++){
        sum_all += arr[i];
    }

    for(int i=1;i<=n;i++){
        float sum = 0;
        for(int j=i;j<=n;j++){
            sum += arr[j];
            float avg_inrange = sum/(j-i+1);
            float avg_outrange = 0;
            if(n-(j-i+1) > 0) avg_outrange = (sum_all-sum)/(n-(j-i+1));
            if(avg_inrange > avg_outrange) printf("%d %d\n",i,j);
        }
    }
}