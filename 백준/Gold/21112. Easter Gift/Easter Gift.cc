#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

struct UF
{
    vector<int> p;

    public:
        UF(int n)
        {
            p.resize(n);
            for(int i = 0; i<n; i++) p[i] = i;
        }

        int Find(int x)
        {
            if(x == p[x]) return x;
            else return p[x] = Find(p[x]);
        }

        void Union(int x, int y)
        {
            x = Find(x);
            y = Find(y);
            if(x != y) p[x] = y;
        }
};


signed main()
{
    FASTIO;
    
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    if(is_sorted(a.begin(), a.end())){
        cout << "0\n";
        return 0;
    }

    sort(b.begin(), b.end());

    vector<int> aitobi(n);
    for(int i = 0; i<n; i++){
        aitobi[i] = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    }
    
    ll lo = 0, hi = 1e+18+1;
    while(lo+1<hi){
        ll k = lo+hi>>1;
        
        UF uf(n);
        for(int i = 1; i<n; i++){
            if(b[i]-b[i-1]<=k) uf.Union(i, i-1);
        }

        bool flag = true;
        for(int i = 0; i<n; i++){
            if(a[i] == b[i]) continue;
            if(uf.Find(i) != uf.Find(aitobi[i])){
                flag = false;
                break;
            }
        }

        if(flag) hi = k;
        else lo = k;
    }

    cout << hi;
    return 0;
}