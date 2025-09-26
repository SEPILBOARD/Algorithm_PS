#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> a[30'001];
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
        cin >> a[i].first;
    }
    for(int i = 0; i<n; i++){
        cin >> a[i].second;
    }

    sort(a, a+n, compare);
    int idx = 0;
    for(int i = 1; i<n; i++){
        while(idx<i && a[idx].first+a[idx].second < a[i].first) idx++;
        if(idx == i){
            cout << "엄마 나 전역 늦어질 것 같아\n";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다\n";
    
    return 0;
}