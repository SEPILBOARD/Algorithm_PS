#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

struct Point{
    int x, y;
    bool operator==(Point o){
        return x==o.x && y==o.y;
    }
};

int ccw(Point p1, Point p2, Point p3)
{
    int s = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    s -= p2.x*p1.y + p3.x*p2.y + p1.x*p3.y;
    if(s>0) return 1;
    else if(s==0) return 0;
    else return -1;
}

bool isbtw(Point p1, Point p2, Point bt)
{
    if(min(p1.x, p2.x) <= bt.x && bt.x <= max(p1.x, p2.x)){
        if(min(p1.y, p2.y) <= bt.y && bt.y <= max(p1.y, p2.y)) return true;
        else return false;
    }
    else return false;
}

Point p[4];

signed main()
{
    FASTIO;
    for(int i = 0; i<4; i++){
        cin >> p[i].x >> p[i].y;
    }

    if(p[2]==p[0] || p[2]==p[1] || p[3]==p[0] || p[3]==p[1]){
        cout << 1;
        return 0;
    }
    
    int ccw1 = ccw(p[0], p[1], p[2]);
    int ccw2 = ccw(p[0], p[1], p[3]);
    int ccw3 = ccw(p[2], p[3], p[0]);
    int ccw4 = ccw(p[2], p[3], p[1]);

    if(ccw1*ccw2 <0 && ccw3*ccw4 <0) cout << 1;

    else if(!ccw1 && isbtw(p[0], p[1],p[2])) cout << 1;
    else if(!ccw2 && isbtw(p[0], p[1],p[3])) cout << 1;
    else if(!ccw3 && isbtw(p[2], p[3],p[0])) cout << 1;
    else if(!ccw4 && isbtw(p[2], p[3],p[1])) cout << 1;
    else cout << 0;
    
    return 0;
}