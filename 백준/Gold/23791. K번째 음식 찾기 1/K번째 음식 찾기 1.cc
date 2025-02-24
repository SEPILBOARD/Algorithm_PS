#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, q, he, ye, k;
int h[100001];
int y[100001];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> h[i];
    for(int i = 1; i<=n; i++) cin >> y[i];
    
    cin >> q;
    while(q--){
        cin >> he >> ye >> k;
        //mid가 k번째 이상인가? FFFTTTT
        //한식에서 찾기
        int lo = 0, hi = he+1;
        while(lo+1<hi){
            int mid = (lo+hi)/2;
            if(k <= mid) hi = mid; //무조건 k이상
            else if(k-mid <= ye){                
                if(h[mid]>=y[k-mid]) hi = mid;
                else lo = mid;
            }
            else lo = mid;
        }

        if(hi <= he && lower_bound(y+1, y+ye+1, h[hi])-(y+1) == k-hi){
            cout << "1 " << hi <<"\n";
        }
        else{
            //양식에서 찾기
            lo = 0, hi = ye+1;
            while(lo+1<hi){
                int mid = (lo+hi)/2;
                if(k <= mid) hi = mid; //무조건 k이상
                else if(k-mid <= he){                
                    if(y[mid]>=h[k-mid]) hi = mid;
                    else lo = mid;
                }
                else lo = mid;
            }
            cout << "2 " <<hi <<"\n";
        }
    }
    return 0;
}