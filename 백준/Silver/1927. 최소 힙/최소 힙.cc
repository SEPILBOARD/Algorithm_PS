#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int main()
{
    FASTIO;
    int q; cin >> q;
    while(q--){
        int e; cin >> e;
        if(e) pq.push(e);
        else{
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}