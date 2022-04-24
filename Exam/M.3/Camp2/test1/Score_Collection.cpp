#include <bits/stdc++.h>
using namespace std;

struct person{
    string name;
    int score,assist;
};

bool compare(const person &a ,const person &b){
    if(a.score != b.score) return a.score > b.score;
    else return a.assist > b.assist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<person> v[2]; //v[0] -> team A ,v[1] -> team B
    for(int i=0;i<n;i++){
        person inp;
        char team;
        cin >> team >> inp.name >> inp.assist;
        bool ck = false;
        int ind = team - 'A'; //if team=A than ind=0 and if team=B than ind=1
        for(int i=0;i<v[ind].size();i++){
            if(v[ind][i].name == inp.name){
                v[ind][i].score += 2;
                v[ind][i].assist = inp.assist;

                ck = true;
                break;
            }
        }
        if(!ck){
            person temp;
            temp.name = inp.name;
            temp.score = 2;
            temp.assist = inp.assist;
            v[team - 'A'].push_back(temp);
        }
    }
    //sort
    sort(v[0].begin() ,v[0].end() ,compare);
    sort(v[1].begin() ,v[1].end() ,compare);
    
    // find suma and sumb
    int suma=0,sumb=0;
    for(auto e:v[0]) suma += e.score;
    for(auto e:v[1]) sumb += e.score;
    
    //print team A
    cout << "A " << suma << endl; 
    for(auto e:v[0]) cout << e.name << ' ' << e.score << ' ' << e.assist << endl;

    //print team B
    cout << "B " << sumb << endl; 
    for(auto e:v[1]) cout << e.name << ' ' << e.score << ' ' << e.assist << endl;
}
/*
7
A Mark 1
A Monty 3
B Johnson 2
B Johnson 3
A Mark 2
B Johnny 4
B Johnny 4
*/