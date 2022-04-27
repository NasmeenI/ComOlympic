#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> v = {1,2,3,4,5};
vector<int> comb;

void print(vector<int> temp){
    for (int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
    cout << endl;
}

void combination(vector<int> temp ,int st ,int k){
    if(!k){
        print(comb);
        return;
    }
    for(int i=st;i<=temp.size()-k;i++){
        comb.push_back(temp[i]);
        combination(temp ,i+1 ,k-1);
        comb.pop_back();
    }
}

void permutations_v1(vector<int> temp){
    do {
        print(temp);
    } while (next_permutation(temp.begin() ,temp.end()));
}

void permutations_v2(vector<int> temp, int l, int r){
    if(l == r){
        print(temp);
        return ;
    }
    for(int i = l; i <= r; i++){
        swap(temp[l], temp[i]);
        permutations_v2(temp, l+1, r);
        swap(temp[l], temp[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    permutations_v1(v);
    permutations_v2(v ,0 ,v.size()-1);
    combination(v ,0 ,3);
}
