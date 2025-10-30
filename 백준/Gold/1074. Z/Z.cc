#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, r, c;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> r >> c;
    
    while(N){
        N--;
        if(r<pow(2,N)){
            if(c<pow(2,N)) continue;
            else{
                ans += pow(2,N*2);
                c -= pow(2,N);
            }
        }
        else{
            if(c<pow(2,N)){
                ans += pow(2,N*2)*2;
                r -= pow(2,N);
            }
            else{
                ans += pow(2,N*2)*3;
                r -= pow(2,N);
                c -= pow(2,N);
            }
        }
    }
    cout << ans;
    return 0;
}