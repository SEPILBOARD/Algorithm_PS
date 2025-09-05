#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

bool isnp[2'000'001];
bool v[2'000'001];
vector<int> p;

int n;
int a[1'000];
int tcnt[2];
vector<int> k;
map<int, int> kcnt;
map<int, int> cnt;

void makePrime()
{
    isnp[0] = true;
    isnp[1] = true;
    for(int i = 2; i<=2'000'000; i++){
        if(isnp[i]) continue;
        if(i<=2000) p.push_back(i);
        for(int j = i+i; j<=2'000'000; j+=i){
            isnp[j] = true;
        }
    }
}

vector<int> primeFtz(int x)
{
    vector<int> ret;
    for(int e: p){
        if(x%e == 0){
            ret.push_back(e);
            while(x%e == 0){
                x/=e;
            }
            if(!isnp[x]){
                ret.push_back(x);
                return ret;
            }
        }
    }
    return ret;
}

signed main()
{
    FASTIO;
    makePrime();

    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int diff = a[j] - a[i];
            if(diff == 1) continue;
            
            if(!isnp[diff]){
                int c = ++kcnt[diff];
                if(c==1) k.push_back(diff);
            }
            else{
                vector<int> pf = primeFtz(diff);
                for(int e: pf){
                    int c = ++kcnt[e];
                    if(c==1) k.push_back(e);
                }
            }
        }
    }
    
    int ans = 1;
    for(int e: k){
        if(kcnt[e]<n/2) continue;
        cnt.clear();
        for(int i = 0; i<n; i++){
            int tans = ++cnt[a[i]%e];
            ans = max(ans, tans);
        }
    }

    cout << ans;
    return 0;
}