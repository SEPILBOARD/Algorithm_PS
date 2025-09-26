#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[30'001];
vector<pair<int, int>> swp;

bool compare(pair<int, int> &fs, pair<int, int> &sc)
{
    if(fs.first == sc.first) return fs.second > sc.second;
    return fs.first < sc.first;
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        swp.push_back({a[i], 1});
    }
    for(int i = 0; i<n; i++){
        int r;
        cin >> r;
        swp.push_back({a[i]+r, -1});
    }

    sort(swp.begin(), swp.end(), compare);
    int cnt = 0;
    int idx = 0;
    for(auto [pos, r] : swp){
        cnt += r;
        idx++;
        if(cnt == 0 && idx != 2*n){
            cout << "엄마 나 전역 늦어질 것 같아\n";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다\n";
    
    return 0;
}