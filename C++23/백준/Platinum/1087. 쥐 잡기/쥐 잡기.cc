#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
tuple<int,int,int,int> a[51];

double L(double t)
{
    double mnx = 1e+18;
    double mxx = -1e+18;
    double mny = 1e+18;
    double mxy = -1e+18;

    for(int i = 0; i<n; i++){
        auto[x, y, vx, vy] = a[i];
        double nx = t*vx+x;
        double ny = t*vy+y;

        mnx = min(mnx, nx);
        mxx = max(mxx, nx);
        mny = min(mny, ny);
        mxy = max(mxy, ny);
    }

    return max(mxx-mnx, mxy-mny);
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y, vx, vy;
        cin >> x >> y >> vx >> vy;
        a[i] = {x, y, vx, vy};
    }

    double lo = 0;
    double hi = 1e+12;
    for(int i = 0; i<=200; i++){
        double l = (lo+lo+hi)/3.0; 
        double h = (lo+hi+hi)/3.0; 
        
        if(L(l)<L(h)) hi = h;
        else lo = l;
    }

    cout.precision(10);
    cout<<fixed;
    cout << L(lo);

    return 0;
}