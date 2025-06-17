#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
queue<int> q;

int main()
{
    FASTIO;
    cin >> n >> k;
    
    for(int i = 1; i<=n; i++) q.push(i);

    while(q.size()>k){
        q.push(q.front());
        for(int i = 0; i<k; i++) q.pop();
    }
    cout << q.front();
    return 0;
}