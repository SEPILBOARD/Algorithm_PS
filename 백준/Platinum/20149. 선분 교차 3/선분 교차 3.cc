#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

struct Point
{
    int x, y;
    double xd, yd;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {xd=x, yd=y;}
    Point(double _x, double _y) : xd(_x), yd(_y) { }
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
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

double cross(const Point& a, const Point& b){ return a.x*b.y - a.y*b.x; }

pair<int, Point> isCross(const Point &a1, const Point &a2, const Point &b1, const Point &b2)
{
    int ccw1 = ccw(a1, a2, b1);
    int ccw2 = ccw(a1, a2, b2);
    int ccw3 = ccw(b1, b2, a1);
    int ccw4 = ccw(b1, b2, a2);

    //교점 1개, 끝점X
    if(ccw1*ccw2 <0 && ccw3*ccw4 <0){
        double d = (a1.x-a2.x)*(b1.y-b2.y) - (a1.y-a2.y)*(b1.x-b2.x);
        double tx = (cross(a1, a2)*(b1.x-b2.x)) - (cross(b1, b2)*(a1.x-a2.x));
        double ty = (cross(a1, a2)*(b1.y-b2.y)) - (cross(b1, b2)*(a1.y-a2.y));
        Point ret(tx/d, ty/d);
        return {1, ret};
    }

    //전부 일직선
    if((ccw1==0 && ccw2==0)){
        // -- --
        if(max(a1.x, a2.x) < min(b1.x, b2.x)) return {0, a1};
        if(max(a1.y, a2.y) < min(b1.y, b2.y)) return {0, a1};
        if(max(b1.x, b2.x) < min(a1.x, a2.x)) return {0, a1};
        if(max(b1.y, b2.y) < min(a1.y, a2.y)) return {0, a1};

        // --.--
        if(a1==b1 && !isbtw(a1,a2,b2) && !isbtw(b1,b2,a2)) return {1, a1};
        if(a1==b2 && !isbtw(a1,a2,b1) && !isbtw(b1,b2,a2)) return {1, a1};
        if(a2==b1 && !isbtw(a1,a2,b2) && !isbtw(b1,b2,a1)) return {1, a2};
        if(a2==b2 && !isbtw(a1,a2,b1) && !isbtw(b1,b2,a1)) return {1, a2};

        // -.-.-
        return {2, a1};
    }    

    //교점 1개, 끝점
    if(!ccw1 && isbtw(a1, a2, b1)) return {1, b1};
    if(!ccw2 && isbtw(a1, a2, b2)) return {1, b2};
    if(!ccw3 && isbtw(b1, b2, a1)) return {1, a1};
    if(!ccw4 && isbtw(b1, b2, a2)) return {1, a2};

    //교점 X
    return {0, a1};
}

Point p[4];

signed main()
{
    FASTIO;
    int n;
    for(int i = 0; i<4; i++){
        int x, y;
        cin >> x >> y;
        Point pt(x, y);
        p[i] = pt;
    }
    
    auto[ans, pt] = isCross(p[0], p[1], p[2], p[3]);
    if(ans == 0) cout << "0\n";
    else if(ans == 2) cout << "1\n";
    else{
        cout << "1\n";
        cout.setf(ios::fixed);
        cout.precision(11);
        cout << pt.xd <<" " << pt.yd <<"\n";
    }
    
    return 0;
}