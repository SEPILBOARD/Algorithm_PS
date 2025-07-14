#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
#define ll long long int

int n, h;
pair<int, int> ab[200'001];
vector<int> itov;
map<int, int> vtoi;

int cyc[600'041];
vector<int> len;
ll psumlen[600'040];

int Q, q;

signed main()
{
    FASTIO;
    cin >> n >> h;
    itov.push_back(1);
    itov.push_back(h);
    itov.push_back(h+1);
    for(int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        ab[i] = {a, b};
        itov.push_back(a);
        itov.push_back(b);
        itov.push_back(b+1);
    }
    
    sort(itov.begin(), itov.end());
    itov.erase(unique(itov.begin(), itov.end()), itov.end());
    for(int i = 0; i<itov.size(); i++) vtoi[itov[i]] = i;
    
    //시작, 종료 구간
    for(int i = 0; i<n; i++){
        auto [a, b] = ab[i];
        cyc[vtoi[a]]++;
        cyc[vtoi[b+1]]--;
    }

    int psum = cyc[0];
    int cur_s = 0;
    int mxidx = vtoi[h+1];

    // for(int i = 0; i<=mxidx; i++){
    //     cout << cyc[i];
    // }cout << "\n";
    
    for(int i = 1; i< mxidx; i++){
        if(psum != 0){
            psum += cyc[i];
            if(psum == 0) cur_s = i;
        }
        else{ // psum == 0
            psum += cyc[i];
            if(psum != 0){
                len.push_back(itov[i]-itov[cur_s]+1);
            }
        }
    }
    if(psum == 0) len.push_back(h+1-itov[cur_s]+1);
    
    //구간 길이 누적합
    sort(len.begin(), len.end());
    if(len.size()>0) psumlen[(int)len.size()-1] = len[(int)len.size()-1];
    for(int i = len.size()-2; i>=0; i--){
        psumlen[i] = psumlen[i+1] + len[i];
    }

    cin >> Q;
    for(int i = 0; i<Q; i++){
        cin >> q;
        int idx = upper_bound(len.begin(), len.end(), q)-len.begin();
        ll ans = psumlen[idx];
        ans = ans - (ll)(len.size()-idx)*(ll)q;
        cout << ans << "\n";

    }
    return 0;
}