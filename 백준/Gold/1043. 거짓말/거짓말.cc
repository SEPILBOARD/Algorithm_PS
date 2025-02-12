#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, ans;
int p[51];
vector<int> v[50];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y) p[y] = x;
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        p[i] = i;
    }

    int numk; cin >> numk;
    if(numk == 0){
        cout << m;
        return 0;
    }

    int tp; cin >> tp;
    for(int i = 1; i<numk; i++){
        int e; cin >> e;
        Union(tp, e);
    }

    for(int i = 0; i<m; i++){
        int num; cin >> num;
        while(num--){
            int e; cin >> e;
            v[i].push_back(e);
            Union(e, v[i][0]);
        }
    }

    for(int i = 0; i<m; i++){
        bool exist = false;
        for(int e: v[i]){
            if(Find(tp) == Find(e)){
                exist = true;
                break;
            }
        }
        if(!exist) ans ++;
    }
    cout << ans;
    return 0;
}