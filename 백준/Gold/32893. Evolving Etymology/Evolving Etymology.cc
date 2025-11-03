#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
ll k;
string s;

ll pw(int a, ll ex)
{
    if(ex == 0) return 1;
    ll temp = pw(a, ex/2)%(n);
    if(ex % 2 ==1){
        ll k = temp * temp % (n);
        k = k * a%(n);
        return k;
    }
    return temp * temp % (n);
}

signed main()
{
    FASTIO;
    cin >> n >> k;
    cin >> s;

    for(int i = 0; i<n; i++){
        ll idx = pw(2, k)*i%n;
        cout << s[idx];
    }

    return 0;
}