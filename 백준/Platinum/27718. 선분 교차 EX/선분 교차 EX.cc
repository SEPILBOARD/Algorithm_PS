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

int isCross(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
    int ccw1 = ccw(p1, p2, p3);
    int ccw2 = ccw(p1, p2, p4);
    int ccw3 = ccw(p3, p4, p1);
    int ccw4 = ccw(p3, p4, p2);

    //교점 1개, 끝점X
    if(ccw1*ccw2 <0 && ccw3*ccw4 <0) return 2;

    //전부 일직선
    if((ccw1==0 && ccw2==0) || (ccw3==0 && ccw4==0)){
        if(p1.x != p2.x){
            int p1x = min(p1.x, p2.x);
            int p2x = max(p1.x, p2.x);
            int p3x = min(p3.x, p4.x);
            int p4x = max(p3.x, p4.x);
            if(p1x > p3x){
                swap(p1x, p3x);
                swap(p2x, p4x);
            }

            if(p2x == p3x) return 1; // --.--
            if(p1x <= p3x && p3x <= p2x) return 3; // -.-.-
            else return 0; // --  --
        }
        else{
            int p1y = min(p1.y, p2.y);
            int p2y = max(p1.y, p2.y);
            int p3y = min(p3.y, p4.y);
            int p4y = max(p3.y, p4.y);
            if(p1y > p3y){
                swap(p1y, p3y);
                swap(p2y, p4y);
            }

            if(p2y == p3y) return 1; // --.--
            if(p1y <= p3y && p3y <= p2y) return 3; // -.-.-
            else return 0; // --  --
        }
    }    

    //교점 1개, 끝점
    if(!ccw1 && isbtw(p1, p2, p3)) return 1;
    if(!ccw2 && isbtw(p1, p2, p4)) return 1;
    if(!ccw3 && isbtw(p3, p4, p1)) return 1;
    if(!ccw4 && isbtw(p3, p4, p2)) return 1;

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