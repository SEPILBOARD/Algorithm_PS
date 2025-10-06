#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(int k) const { return Point(x * k, y * k); }
    bool operator==(const Point& o) const { return (x==o.x)&&(y==o.y); }
};

int ccw(const Point &p1, const Point &p2, const Point &p3)
{
    int s = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    s -= p2.x*p1.y + p3.x*p2.y + p1.x*p3.y;
    if(s>0) return 1;
    else if(s==0) return 0;
    else return -1;
}

bool isbtw(const Point &p1, const Point &p2, const Point &bt)
{
    if(min(p1.x, p2.x) <= bt.x && bt.x <= max(p1.x, p2.x)){
        if(min(p1.y, p2.y) <= bt.y && bt.y <= max(p1.y, p2.y)) return true;
        else return false;
    }
    else return false;
}

int isCross(const Point &a1, const Point &a2, const Point &b1, const Point &b2)
{
    int ccw1 = ccw(a1, a2, b1);
    int ccw2 = ccw(a1, a2, b2);
    int ccw3 = ccw(b1, b2, a1);
    int ccw4 = ccw(b1, b2, a2);

    //교점 1개, 끝점X
    if(ccw1*ccw2 <0 && ccw3*ccw4 <0) return 2;

    //전부 일직선
    if((ccw1==0 && ccw2==0)){
        // -- --
        if(max(a1.x, a2.x) < min(b1.x, b2.x)) return 0;
        if(max(a1.y, a2.y) < min(b1.y, b2.y)) return 0;
        if(max(b1.x, b2.x) < min(a1.x, a2.x)) return 0;
        if(max(b1.y, b2.y) < min(a1.y, a2.y)) return 0;

        // --.--
        if(a1==b1 && !isbtw(a1,a2,b2) && !isbtw(b1,b2,a2)) return 1;
        if(a1==b2 && !isbtw(a1,a2,b1) && !isbtw(b1,b2,a2)) return 1;
        if(a2==b1 && !isbtw(a1,a2,b2) && !isbtw(b1,b2,a1)) return 1;
        if(a2==b2 && !isbtw(a1,a2,b1) && !isbtw(b1,b2,a1)) return 1;

        // -.-.-
        return 3;
    }    

    //교점 1개, 끝점
    if(!ccw1 && isbtw(a1, a2, b1)) return 1;
    if(!ccw2 && isbtw(a1, a2, b2)) return 1;
    if(!ccw3 && isbtw(b1, b2, a1)) return 1;
    if(!ccw4 && isbtw(b1, b2, a2)) return 1;

    //교점 X
    return 0;
}

Point p[2001][2];

signed main()
{
    FASTIO;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<2; j++){
            cin >> p[i][j].x >> p[i][j].y;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << isCross(p[i][0], p[i][1], p[j][0], p[j][1]);
        }
        cout << "\n";
    }
    
    return 0;
}