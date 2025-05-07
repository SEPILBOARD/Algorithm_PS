#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

double x, y, xx, yy, r, rr;
double dist;

void solve()
{
    cin >> x >> y >> r >> xx >> yy >> rr;
    dist = sqrt(pow(x-xx,2)+pow(y-yy,2));

    if(dist > r+rr){
        cout << "0\n";
    }

    else if(dist < r+rr){
        double temp = dist + min(r, rr);
        if(temp > max(r, rr)) cout << "2\n";
        else if(temp < max(r, rr)) cout << "0\n";
        else{
            if(x==xx && y==yy) cout << "-1\n";
            else cout << "1\n";
        }
    }
    
    else{
        cout << "1\n";
    }
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}