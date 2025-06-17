#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
queue<int> q;

int main()
{
    FASTIO;
    cin >> n >> k;
    
    for(int i = k+1; i<=n; i++) q.push(i);
    for(int i = 1; i<k; i++) q.push(i);
    cout << "<" <<k;
    int cnt = 1;
    while(!q.empty()){
        if(cnt != k){
            q.push(q.front());
            q.pop();
            cnt++;
        }
        else{
            cout << ", " << q.front();
            q.pop();
            cnt = 1;
        }
    }
    cout << ">";
    return 0;
}