#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int ex = 0;

int pow3(int ex)
{
    switch (ex)
    {
    case 1:
        return 3;
    case 2:
        return 9;
    case 3:
        return 27;
    case 4:
        return 81;
    case 5:
        return 243;
    case 6:
        return 729;
    case 7:
        return 2187;
    default:
        break;
    }
}

void ps(int i, int j)
{
    for(int k = 1; k<=ex; k++){
        int p = pow3(k);
        if(p-(2*p/3) < i%p && i%p <= p-(p/3)){     
            if(p-(2*p/3) < j%p && j%p <= p-(p/3)){
                cout << " ";
                return;
            }
        }
    }
    cout <<"*";
}

int main()
{
    FASTIO;
    cin >> n;
    int tmp = n;
    while(tmp--){
        tmp /=3;
        ex++;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            ps(i,j);
        }
        cout <<"\n";
    }
    
    return 0;
}