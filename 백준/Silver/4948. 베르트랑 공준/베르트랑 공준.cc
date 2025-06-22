#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
bool np[250'002];
int pcnt[250'002];

int main()
{
    for(int i = 2; i*i<=250'000; i++){
        if(!np[i]){
            for(int k = i*i; k<=250'000; k += i){
                np[k] = true;
            }
        }
    }

    pcnt[1] = 1;
    for(int i = 2; i<=250'000; i++){
        if(np[i]) pcnt[i] = pcnt[i-1];
        else pcnt[i] = pcnt[i-1]+1;
    }

    FASTIO;

    cin >> n;
    while(n){
        cout << pcnt[2*n] - pcnt[n] <<"\n";
        cin >> n;
    }
    return 0;
}