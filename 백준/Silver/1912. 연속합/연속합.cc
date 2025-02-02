#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[100000];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int sum = a[0];
    int ans = a[0];
    for(int i = 1; i<n; i++){
        if(sum <0) sum = a[i];
        else sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans <<"\n";
    return 0;
}