#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll A, B;

signed main()
{
    FASTIO;
    cin >> A >> B;

    queue<pair<ll, int>> q;
    q.push({A, 1});
    while(!q.empty()){
        auto[cur, d] = q.front();
        q.pop();

        if(cur == B){
            cout << d;
            return 0;
        }

        if(2*cur <= B) q.push({2*cur, d+1});
        if(10*cur+1 <= B) q.push({10*cur+1, d+1});
    }

    cout << "-1";
    return 0;
}