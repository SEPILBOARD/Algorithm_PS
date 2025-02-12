#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, ans;
string mp[1000];
bool v[1000001];
int p[1000001];
set<int> ed;

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

void DFS(int i, int j, int bf)
{
    int cur = m*i+j;
    Union(bf, cur);
    if(v[cur]) return;
    
    v[cur] = true;
    switch (mp[i][j])
    {
    case 'D':
        DFS(i+1,j, cur);
        break;
    case 'L':
        DFS(i,j-1, cur);
        break;
    case 'R':
        DFS(i,j+1, cur);
        break;
    case 'U':
        DFS(i-1,j, cur);
        break;
    default:
        break;
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            p[i*m + j] = i*m + j;
        }
    }


    for(int i = 0; i<n; i++){
        cin >> mp[i];
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i*m+j]) continue;
            DFS(i,j,i*m+j);
        }
    }
    
    for(int i = 0; i<n*m; i++){
        int fd = Find(i);
        if(!ed.count(fd)){
            ans++;
            ed.insert(fd);
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout << Find(p[i*m + j]) <<" ";
    //     }
    //     cout << "\n";
    // }

    cout << ans;
    return 0;
}