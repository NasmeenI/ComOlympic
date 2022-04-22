#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data{
    int team,name,start,speed,startreal;
};

bool compare(const data &a,const data &b){
    return a.speed > b.speed;
}

int main(){
    vector<data> v;
    data temp;
    int n,m,imax=0,jmax=0;
    cin >> n >> m;
    for(int i=0;i<n+m;i++){
        int instart,inspeed;
        cin >> instart >> inspeed;
        temp.start = instart;
        temp.speed = inspeed;
        temp.name = i+1;
        temp.startreal = 1;
        if(i < n){
            temp.team = 1;
            imax = max(imax ,instart);
        }
        else{
            temp.team=2;
            jmax = max(jmax ,instart);
        }
        v.push_back(temp);
    }
    sort(v.begin() ,v.end() ,compare);

    int arr[imax+2][jmax+2],arr2[n+m+1];
    for(int i=1;i<n+m;i++) arr2[i] = 0;

    for(int i=1;i<=imax+1;i++) for(int j=1;j<=jmax+1;j++) arr[i][j] = 0;

    while(!v.empty()){
        for(int k=0;k<v.size();k++){
            if(v[k].team == 1){
                for(int i=v[k].startreal;i<=v[k].speed+v[k].startreal;i++){
                    if(i+1>imax and arr[i][v[k].start] == 0){
                        arr2[v[k].name] = -1;
                        arr[i][v[k].start] = v[k].name;
                        v.erase(v.begin()+k);
                        k--;
                        break;
                    }
                    if(arr[i][v[k].start] == 0) arr[i][v[k].start] = v[k].name;
                    else{
                        arr2[v[k].name] = arr[i][v[k].start];
                        v.erase(v.begin()+k);
                        k--;
                        break;
                    }
                    if(i+1 > v[k].speed) v[k].startreal = i+1;
                }
            }

            else if(v[k].team == 2){
                for(int j=v[k].startreal;j<=v[k].speed+v[k].startreal;j++){
                    if(j+1>imax and arr[v[k].start][j]==0){
                        arr2[v[k].name] = -1;
                        arr[v[k].start][j] = v[k].name;
                        v.erase(v.begin()+k);
                        k--;
                        break;
                    }
                    if(arr[v[k].start][j] == 0) arr[v[k].start][j] = v[k].name;
                    else{
                        arr2[v[k].name] = arr[v[k].start][j];
                        v.erase(v.begin()+k);
                        k--;
                        break;
                    }
                    if(j+1 > v[k].speed){
                        v[k].startreal = j+1;
                    }
                }
            }
        }
    }

    for(int i=1;i<=imax+1;i++){
        for(int j=1;j<=jmax+1;j++) cout << arr[i][j] << ' ';
        cout << endl;
    }
    for(int i=1;i<=n+m;i++) cout << arr2[i] << endl;
}
/*
2 2
1 1
2 10
1 5
2 1
*/

