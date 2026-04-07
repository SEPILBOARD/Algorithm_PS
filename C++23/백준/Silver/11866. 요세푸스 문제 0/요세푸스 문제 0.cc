#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, k;
queue<int> q;

signed main()
{
    FASTIO;

    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        q.push(i);
    }

    cout << '<';
    while(q.size()>1){
        for(int i = 0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }

        cout << q.front() <<", ";
        q.pop();
    }

    cout << q.front();
    cout << '>';
    
    return 0;
}