//Polynomal Camp2/test1 2564
#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<pi> v1,v2;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v1.push_back({a ,b});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v2.push_back({a ,b});
    }

    int ind1=0 ,ind2=0;
    while(1){
        if(ind1 == n and ind2 == m) return 0;
        else if(ind1 == n){
            while(ind2 != m){
                cout << v2[ind2].first << ' ' << v2[ind2].second << ' ';
                ind2++;
            }
            return 0;
        }
        else if(ind2 == m){
            while(ind1 != n){
                cout << v1[ind1].first << ' ' << v1[ind1].second << ' ';
                ind1++;
            }
            return 0;
        }
        
        if(v1[ind1].second > v2[ind2].second){
            cout << v1[ind1].first << ' ' << v1[ind1].second << ' ';
            ind1++;
        }
        else if(v1[ind1].second < v2[ind2].second){
            cout << v2[ind2].first << ' ' << v2[ind2].second << ' ';
            ind2++;
        }
        else{
            int temp = v1[ind1].first + v2[ind2].first;
            if(temp != 0) cout << temp << ' ' << v1[ind1].second << ' ';
            ind1++;
            ind2++;
        }
    }
}
/* 
4 3
3 5 5 2 -3 1 8 0
2 4 -3 2 9 0

4 3
3 5 5 2 -3 1 8 0
2 4 -5 2 9 0

4 2
3 5 5 2 -3 1 8 0
2 4 -3 2
out put -> 3 5 2 4 2 2 -3 1 8 0
*/
