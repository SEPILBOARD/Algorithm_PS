#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, x;
int room[100001];
int club[100001];

int main()
{
    FASTIO;
    cin >> n >> m >> x;
    for(int i = 1; i<=n; i++) cin >> room[i];
    for(int i = 1; i<=m; i++) cin >> club[i];

    sort(room+1, room+n+1);
    sort(club+1, club+m+1);

    int lo = 0, hi = n+1;
    if(m<n) hi = m+1;
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        int cur_x = x;
        int ridx = 1;
        bool flag = true;
        for(int i = m-mid+1; i<=m; i++){
            cur_x -= max(room[ridx] - club[i], 0);
            if(cur_x<0){
                flag = false;
                break;
            }
            ridx++;
        }
        if(flag) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}