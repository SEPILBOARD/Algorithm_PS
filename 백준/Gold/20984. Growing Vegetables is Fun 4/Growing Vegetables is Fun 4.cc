#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int

int n;
int a[200'001];
ll ans, ans1, ans2;

signed main()
{
    FASTIO;
    bool olm = true;
    bool nelim = true;
    bool areadly = true;
    cin >> n;
    cin >> a[0];
    for(int i = 1; i<n; i++){
        cin >> a[i];

        if(!olm && !nelim && a[i-1]<a[i]) areadly = false;
        if(a[i-1]==a[i]) areadly = false;

        if(a[i-1]<=a[i]) nelim = false;
        if(a[i-1]>=a[i]) olm = false;
        
    }
    if(a[0]>=a[1]) areadly = false;

    if(n == 2 && a[0] == a[1]){
        cout << "1";
        return 0;
    }

    if((olm || nelim || areadly)){
        cout << 0;
        return 0;
    }

    int lo = 1; int hi = n-2;
    while(lo<=hi){
        while(a[lo-1] < a[lo] && lo<hi) lo++;
        while(a[hi] > a[hi+1] && lo<hi) hi--;

        if(ans1 == 0) ans1 = (ll)a[lo-1] - (ll)a[lo] + 1ll;
        if(ans2 == 0) ans2 = (ll)a[hi+1] - (ll)a[hi] + 1ll;

        // cout << lo <<", " << hi <<": " << ans1 << ", " <<ans2 <<"\n";
        if(lo == hi){
            if(ans1 == 0){
                ans += ans2;
                break;
            }
            if(ans2 == 0){
                ans += ans1;
                break;
            }
            ans += max(0ll,min(ans1, ans2));
            break;
        }

        if(ans1 < ans2){
            ans += ans1;
            ans2 -= ans1;
            ans1 = 0;
            lo++;
        }
        else if(ans1 > ans2){
            ans += ans2;
            ans1 -= ans2;
            ans2 = 0;
            hi--;
        }
        else{
            ans += ans1;
            ans1 = 0;
            ans2 = 0;

            if(lo+1 == hi && a[lo] == a[hi]) ans++;
            lo++;
            hi--;
        }
    }
    // cout << ans1 <<" " <<ans2 <<"\n";
    cout << ans;
    return 0;
}