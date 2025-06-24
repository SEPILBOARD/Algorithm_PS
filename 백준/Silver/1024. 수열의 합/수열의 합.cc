#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, l;

int main()
{
    FASTIO;
    cin >> n >> l;

    for(int k = l; k<=100; k++){
        int x = n - k*(1+k)/2;
        if(x%k) continue;
        
        int a = x/k;
        if(a<-1) continue;
        
        for(int i = 1; i<=k; i++) cout << a+i <<" ";
        return 0;
    }
    cout << -1;
    return 0;
}