#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

double h, v;
double ansH, ansV;

int main()
{
    FASTIO;
    cin >> h >> v;

    double c = sqrt(pow(h,2)+pow(v,2));
    double tp = h/(c+h) * v;
    ansH = sqrt(pow(h,2)+pow(tp,2))/2;
    
    double tp2 = h*tp/(ansH*2);
    ansV = tp*v/tp2/2;

    // cout << fixed << setprecision(6);
    cout << ansH <<" " << ansV;
    return 0;
}