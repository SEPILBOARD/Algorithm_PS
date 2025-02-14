#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
/*https://www.acmicpc.net/board/view/13512*/
unordered_map<string, int> idx;
int p[200001];
int cnt[200001];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y){
        p[y] = x;
        cnt[x] += cnt[y];
    }
    cout << cnt[x] <<"\n";
}

void solve()
{
    idx.clear();
    
    int ic = 1;
    int f; cin >> f;
    for(int i = 0; i < 2*f; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    
    while(f--){
        string a, b; cin >> a >> b;
        int aidx, bidx;
        int ans = 0;
        
        if(idx.find(a) == idx.end()){
            aidx = ic;
            idx[a] = ic++;
        }
        else aidx = idx[a];

        if(idx.find(b) == idx.end()){
            bidx = ic;
            idx[b] = ic++;
        }
        else bidx = idx[b];

        Union(aidx, bidx);
        // int sf = Find(aidx);
        // for(int e = 1; e < ic; e++){
        //     if(sf == Find(e)) ans++;
        // }
        // cout << ans <<"\n";
    }
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}