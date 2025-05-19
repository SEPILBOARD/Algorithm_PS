#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> p[100'001];

bool compare(pair<int, int> f, pair<int, int> s)
{
    if(f.first == s.first) return f.second < s.second;
    return f.first < s.first;
}

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        p[i] = {x, y};
    }

    sort(p, p+n, compare);
    for(int i = 0; i<n; i++){
        cout << p[i].first <<" " <<p[i].second <<"\n";
    }
    return 0;
}