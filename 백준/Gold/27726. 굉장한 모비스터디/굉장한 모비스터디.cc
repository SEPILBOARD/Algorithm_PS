#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m1, m2, m3, ans;

int p[4][100001];

vector<int> mb[100001];

int Find(int x, int* p)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x], p);
}

void Union(int x, int y, int* p)
{
    x = Find(x, p);
    y = Find(y, p);
    if(x == y) return;
    else if(x>y) p[x] = y;
    else p[y] = x;
}

void solve(int m, int* p)
{
    while(m--){
        int a, b; cin >> a >> b;
        Union(a, b, p);
    }
}

bool compare(int a, int b)
{
    for(int i = 0; i<3; i++){
        int ra = Find(a, p[i]);
        int rb = Find(b, p[i]);
        if(ra != rb) return ra < rb;
    }
    return a<b;
}

int main()
{
    FASTIO;
    cin >> n;
    cin >> m1 >> m2 >> m3;
    
    for(int i = 1; i<=n; i++) p[0][i] = p[1][i] = p[2][i] = p[3][i] = i;

    solve(m1, p[0]);
    solve(m2, p[1]);
    solve(m3, p[2]);

    sort(p[3]+1, p[3]+n+1, compare);
    mb[1].push_back(1);
    int bf = 1;
    for(int i = 2; i<=n; i++){
        int cur = p[3][i];
        if(Find(bf, p[0]) == Find(cur, p[0]) && Find(bf, p[1]) == Find(cur, p[1]) && Find(bf, p[2]) == Find(cur, p[2])){
            if(mb[bf].size() == 1) ans++;
            mb[bf].push_back(cur);
        }
        else{
            mb[cur].push_back(cur);
            bf = cur;
        }
    }
    cout << ans <<"\n";
    for(int i = 1; i<=n; i++){
        if(mb[i].size()>1){
            for(int e: mb[i]){
                cout << e <<" ";
            }
            cout << "\n";
        }
    }

    return 0;
}