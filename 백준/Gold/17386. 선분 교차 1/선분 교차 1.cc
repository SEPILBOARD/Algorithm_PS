#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

pair<int, int> p[4];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int s = a.first*b.second + b.first*c.second + c.first*a.second;
    s -= b.first*a.second + c.first*b.second + a.first*c.second;
    if(s<0) return -1;
    else if(s==0) return 0;
    else return 1;
}

bool iscross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    if(ccw(a, b, c)*ccw(a, b, d)<=0 && ccw(c, d, a)*ccw(c, d, b)<=0) return true;
    else return false;
}

signed main()
{
    FASTIO;
    for(int i = 0; i<4; i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    if(iscross(p[0], p[1], p[2], p[3])) cout << 1;
    else cout << 0;
    return 0;
}