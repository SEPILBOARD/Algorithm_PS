#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string solve(int nx, int ny, double w)
{
    double endClear = 0.0;
    vector<double> x(nx);
    vector<double> y(ny);
    
    for(int i = 0; i<nx; i++) cin >> x[i];
    for(int i = 0; i<ny; i++) cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i = 0; i<nx; i++){
        if(endClear+w < x[i]) return "NO\n";
        
        endClear = x[i];
    }
    if(endClear+w/2 < 75.0) return "NO\n";

    endClear = 0.0;
    for(int i = 0; i<ny; i++){
        if(endClear+w < y[i]) return "NO\n";
        
        endClear = y[i];
    }
    if(endClear+w/2 < 100.0) return "NO\n";

    return "YES\n";
}

signed main()
{
    FASTIO;
    int nx, ny;
    double w;
    while(true){
        cin >> nx >> ny >> w;
        if(nx == 0 && ny == 0 && w == 0.0) break;

        cout << solve(nx, ny, w);
    }
    
    return 0;
}