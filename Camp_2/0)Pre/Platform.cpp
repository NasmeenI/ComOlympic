#include <iostream>
#include <vector>
using namespace std;

struct data{
    int h,start,stop;
};

int main(){
    int n,imax=0,jmax=0;
    vector<data> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int inh,instart,instop;
        cin >> inh >> instart >> instop;
        imax = max(imax ,inh);
        jmax = max(jmax ,instop);

        data temp;
        temp.h = inh;
        temp.start = instart;
        temp.stop = instop;
        v.push_back(temp);
    }

    int arr[imax+1][jmax];
    for(int i=0;i<=imax;i++) for(int j=0;j<jmax;j++) arr[i][j] = 0;

    for(int k=0;k<n;k++){
        for(int j=v[k].start;j<v[k].stop;j++) arr[imax-v[k].h][j] = 1;
    }   

    int c = 0;
    for(int k=0;k<n;k++){
        for(int i=imax-v[k].h+1;i<=imax;i++){
            if(arr[i][v[k].start] == 1){
                c++;
                break;
            }
            else if(arr[i][v[k].start] == 0) c++;
        }
        for(int i=imax-v[k].h+1;i<=imax;i++){
            if(arr[i][v[k].stop-1] == 1){
                c++;
                break;
            }
            else if(arr[i][v[k].stop-1] == 0) c++;
        }
    }
    cout << c;
}

