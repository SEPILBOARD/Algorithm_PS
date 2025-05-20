#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
deque<int> dq;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) dq.push_back(i);

    while(!dq.empty()){
        int ans = dq.front();
        dq.pop_front();
        if(dq.empty()){
            cout << ans;
            return 0;
        }
        dq.push_back(dq.front());
        dq.pop_front();
    }
    
    return 0;
}