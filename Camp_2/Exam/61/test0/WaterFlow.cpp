#include <iostream>
using namespace std;

int main(){
    int p,q,k;
    cin >> p >> q >> k;
    int arr[q+1][p+1];
    for(int i=1;i<=q;i++) for(int j=1;j<=p;j++) cin >> arr[i][j];

    while(k--){
        int x,y;
        cin >> x >> y;
        int cnt = 0;
        while(1){
            if(arr[y][x] == 1){
                y--;
                if(y == 0){
                    cout << x << ' ' << 1 << endl;
                    break;
                }
            }
            else if(arr[y][x] == 2){
                x++;
                if(x > p){
                    cout << p << ' ' << y << endl;
                    break;
                }
            }
            else if(arr[y][x] == 3){
                y++;
                if(y > q){
                    cout << x << ' ' << q << endl;
                    break;
                }
            }
            else if(arr[y][x] == 4){
                x--;
                if(x == 0){
                    cout << 1 << ' ' << y << endl;
                    break;
                }
            }
            cnt++;
            if(cnt > p*q){
                cout << "NO" << endl;
                break;
            }
        }
    }
}
