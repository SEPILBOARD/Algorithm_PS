#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
vector<int> a;
int ans[9];
bool ext[10'001];

void bt(int cnt)
{
    if(cnt == m){
        for(int i = 0; i<m; i++)
            cout << ans[i] <<" ";
        cout << "\n";
        return;
    }

    for(int e: a){
        ans[cnt] = e;
        bt(cnt+1);
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        if(!ext[e]){
            a.push_back(e);
            ext[e] = true;
        }
    }
    sort(a.begin(), a.end());
    bt(0);
    return 0;
}