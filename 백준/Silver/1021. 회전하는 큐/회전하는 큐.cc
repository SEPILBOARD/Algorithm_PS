#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[51];
int pos[51];
deque<int> dq;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++) cin >> a[i];
    for(int i = 1; i<=n; i++){
        pos[i] = i;
        dq.push_back(i);
    }
    int ans = 0;
    deque<int> temp;
    for(int i = 0; i<m; i++){
        int fcnt = 0;
        int sz = dq.size();
        while(dq.front() != a[i]){
            temp.push_back(dq.front());
            dq.pop_front();
            fcnt++;
        }
        if((sz+1)/2-1>=fcnt){
            dq.pop_front();
            while(!temp.empty()){
                dq.push_back(temp.front());
                temp.pop_front();
            }
            ans += fcnt;
        }
        else{
            while(!temp.empty()){
                dq.push_front(temp.back());
                temp.pop_back();
            }
            while(dq.back() != a[i]){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
            ans += sz - fcnt;
        }
    }
    cout << ans;
    return 0;
}