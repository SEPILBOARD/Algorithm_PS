#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, W;
double ex, ey;

inline bool isBtwn(double x1, double y1, double x2, double y2, double x3, double y3){
    if(min(x1, x2)<=x3 && x3<=max(x1, x2) && min(y1, y2)<=y3 && y3<=max(y1, y2)) return true;
    else return false;
}


void solve()
{
    cin >> n >> W >> ex >> ey;

    vector<int> w(n);
    vector<vector<pair<double, double>>> xy(n);
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        cin >> w[i];
        for(int j = 0; j<k; j++){
            double x, y;
            cin >> x >> y;
            xy[i].push_back({x, y});
        }
    }

    vector<double> dist(n, 1e+18);
    for(int i = 0; i<n; i++){
        for(int j = 1; j<xy[i].size(); j++){
            auto[x1, y1] = xy[i][j-1];
            auto[x2, y2] = xy[i][j];

            double a =  y1-y2;
            double b =  x2-x1;
            double c =  x1*y2-x2*y1;

            double t = (a*ex + b*ey + c)/(a*a+b*b);
            double xh = ex-a*t;
            double yh = ey-b*t;
            
            if(isBtwn(x1, y1, x2, y2, xh, yh)){
                double tdist = abs(a*ex+b*ey+c)/sqrt(a*a+b*b); 
                dist[i] = min(dist[i], tdist);
            }
            else{
                double tdist1 = sqrt((x1-ex)*(x1-ex) + (y1-ey)*(y1-ey));
                double tdist2 = sqrt((x2-ex)*(x2-ex) + (y2-ey)*(y2-ey));
                dist[i] = min(dist[i], min(tdist1, tdist2));
            }
        }
    }

    vector<vector<double>> dp(n+1, vector<double>(W+5, 1e+18));
    dp[0][0] = 0;
    for(int i = 0; i<n; i++){
        for(int cur = 0; cur<=W; cur++){
            dp[i+1][cur] = min(dp[i+1][cur], dp[i][cur]);
            if(cur+w[i]<W){
                dp[i+1][cur+w[i]] = min(dp[i+1][cur+w[i]], dp[i][cur]+dist[i]);
            }
            else{
                dp[i+1][W] = min(dp[i+1][W], dp[i][cur]+dist[i]);
            }
        }
    }
    
    if(dp[n][W] == 1e+18){
        cout << "Impossible\n";
    }
    else{
        cout << dp[n][W] <<"\n";
    }
    // cout << dp[n][9];
}

signed main()
{
    FASTIO;
    cout.precision(2);
    cout << fixed;

    int t; cin >> t;
    for(int i = 1; i<=t; i++){
        cout << "Data Set "<< i <<": \n";
        solve();
        cout << "\n";
    }    
    return 0;
}