#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> p[100'001];

bool compare(pair<int, int> &fs, pair<int, int> &sc)
{
    if(fs.second ==  sc.second) return fs.first < sc.first;
    return fs.second < sc.second;
}

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0 ; i<n; i++){
        int s, e;
        cin >> s >> e;
        p[i] = {s, e};
    }

    sort(p, p+n, compare);
    int ans = 0;
    int last = 0;
    for(int i = 0; i<n; i++){
        if(p[i].first>=last){
            ans++;
            last = p[i].second;
        }
    }
    cout << ans;
    return 0;
}