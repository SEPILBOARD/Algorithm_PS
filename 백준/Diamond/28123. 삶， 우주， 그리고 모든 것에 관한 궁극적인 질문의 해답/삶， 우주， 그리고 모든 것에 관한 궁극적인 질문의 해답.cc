#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
int n, k, x;

signed main()
{
    FASTIO;
    cin >> n >> k >> x;
    switch (x)
    {
    case 1:
        cout << (n+1)-3*(k-1) -1;
        break;
    case 2:
    case 3:
    case 4:
        cout << (n+1)-3*(k-1) -2;
        break;
    default:
        cout << (n+1)-3*(k-1) -3;
        break;
    }
    return 0;
}