#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

pair<double, double> v[8];
double tl = 0;

double ans[2];
double tans[2];

double area(int a, int b, int c)
{
    double temp = v[a].first*v[b].second + v[b].first*v[c].second + v[c].first*v[a].second;
    temp -= v[b].first*v[a].second + v[c].first*v[b].second + v[a].first*v[c].second;
    return 0.5 * abs(temp);
}

void isans()
{
    if(abs(ans[0]-ans[1]) > abs(tans[0]-tans[1])){
        ans[0] = tans[0];
        ans[1] = tans[1];
    }
}

void tricase(int a, int b, int c)
{
    tans[0] = area(a,b,c);
    tans[1] = tl - tans[0];
    if(abs(ans[0]-ans[1]) > abs(tans[0]-tans[1])){
        ans[0] = tans[0];
        ans[1] = tans[1];
    }
}

int main()
{
    FASTIO;
    cout.precision(5);

    for(int i = 0; i<4; i++){
        double x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    v[4] = {(v[0].first+v[1].first)/2, (v[0].second+v[1].second)/2};
    v[5] = {(v[1].first+v[2].first)/2, (v[1].second+v[2].second)/2};
    v[6] = {(v[2].first+v[3].first)/2, (v[2].second+v[3].second)/2};
    v[7] = {(v[3].first+v[0].first)/2, (v[3].second+v[0].second)/2};

    //전체
    tl = area(0,1,2);
    ans[0] = tl;
    tl += area(0,2,3);
    ans[1] = tl - ans[0];
    
    tricase(0,1,5);
    tricase(0,6,3);

    tricase(0,4,3);
    tricase(0,1,3);
    tricase(3,5,2);

    tricase(0,4,7);
    tricase(0,1,7);
    tricase(7,2,3);
    tricase(7,6,3);

    tricase(4,1,5);
    tricase(4,1,2);

    tans[0] = area(0,1,7);
    tans[0] += area(7,1,5);
    tans[1] = tl-tans[0];
    isans();

    tans[0] = area(0,4,3);
    tans[0] += area(4,6,3);
    tans[1] = tl - tans[0];
    isans();

    cout << min(ans[0],ans[1]) <<" " << max(ans[0], ans[1]);
    return 0;
}