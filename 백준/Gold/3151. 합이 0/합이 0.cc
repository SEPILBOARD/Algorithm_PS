#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int

ll ans;
int n;
vector<int> a;
int pcnt[20001];
int ncnt[20001];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        a.push_back(e);
        if(e<0) ncnt[-e]++;
        else pcnt[e]++;
    }
    // sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            int find =0-a[i]-a[j];
            ll sum;
            if(find<0) sum = ncnt[-find];
            else sum = pcnt[find];
            if(a[i] == find) sum = max(0ll, sum-1);
            if(a[j] == find) sum = max(0ll, sum-1);
            ans += sum;
        }
    }
    cout << ans/3;
    return 0;
}