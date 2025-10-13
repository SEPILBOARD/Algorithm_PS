#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;
#define int long long int

struct Point
{
    int x, y;
};

int ccw(Point a, Point b, Point c){
    ll t = 1ll * a.x*b.y + b.x*c.y + c.x*a.y;
    t -= 1ll * b.x*a.y + c.x*b.y + a.x*c.y;
    if(t<0) return -1;
    else if(t==0) return 0;
    else return 1;
}

Point p[3];

signed main()
{
    FASTIO;
    for(int i = 0; i<3; i++){
        cin >> p[i].x >> p[i].y;
    }

    int a = (p[1].x-p[0].x)*(p[1].x-p[0].x) + (p[1].y-p[0].y)*(p[1].y-p[0].y);
    int b = (p[2].x - p[1].x)*(p[2].x - p[1].x) + (p[2].y - p[1].y)*(p[2].y - p[1].y);
    int c = (p[2].x - p[0].x)*(p[2].x - p[0].x) + (p[2].y - p[0].y)*(p[2].y - p[0].y);

    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);

    if(ccw(p[0], p[1], p[2]) == 0) cout << "X";
    
    else if(a == b && b == c) cout << "JungTriangle";
    
    else if(c > a+b){
        if(a == b || b==c) cout << "Dunkak2Triangle";
        else cout << "DunkakTriangle";
    }
    else if(c == a+b){
        if(a == b || b==c) cout << "Jikkak2Triangle";
        else cout << "JikkakTriangle";
    }
    else{
        if(a == b || b==c) cout << "Yeahkak2Triangle";
        else cout << "YeahkakTriangle";
    }
    
    return 0;
}