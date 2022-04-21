#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using pi = pair<double,double>;

int n;
vector<pi> point;

double caldis(pi a ,pi b){
    double x1 = a.first ,y1 = a.second;
    double x2 = b.first ,y2 = b.second;
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

double divide(int l ,int r){
    if(l == r) return INF;

    int mid = (l+r)/2;
    double disl = divide(l ,mid);
    double disr = divide(mid+1 ,r);
    double mindis = min(disl ,disr);

    vector<pi> temp;
    for(int i=l;i<=r;i++)
        if(caldis(point[i],point[mid]) < mindis) temp.emplace_back(point[i]);

    for(int i=0;i<temp.size();i++)
        for(int j=i+1;j<temp.size();j++)
            mindis = min(mindis ,caldis(temp[i],temp[j]));

    return mindis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        double x,y;
        cin >> x >> y;
        point.emplace_back(x ,y);
    }
    sort(point.begin() ,point.end());

    double mindis = divide(0 ,n-1);
    printf("%.4f",mindis);
    //for(auto e:point) cout << e.first << ' ' << e.second << endl;
}
