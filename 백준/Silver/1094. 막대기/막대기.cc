#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<=6; i++)
        if(n&(1<<i)) ans++;
    cout << ans;
    return 0;
}