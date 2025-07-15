#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
vector<pair<int,int>> stage;

int s = 0;
int ans =0;

bool compare(pair<int,int>&fs, pair<int,int>&sc)
{
    if(fs.second == sc.second)
    {
        return fs.first > sc.first;        
    }
    return fs.second < sc.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i<n; i++)
    {
        int ai, bi; cin >> ai >>bi;
        stage.push_back(make_pair(ai, bi));
    }

    sort(stage.begin(),stage.end(),compare);

    int idx = 0;
    while(idx < n)
    {   
        bool canClear = false;
        if(s<stage[idx].second)
        {
            for(int i = n-1; i>=idx; i--)
            {
                if(stage[i].first == -1 || s<stage[i].first) continue;
                stage[i].first = -1;
                s++;
                ans ++;
                // cout << ans << ": " << stage[i].first <<" " << stage[i].second<<"\n";
                canClear = true;
                break;
            }
        }
        else
        {
            s++;
            ans++;
            // cout << ans << ": " << stage[idx].first <<" " << stage[idx].second<<"\n";
            canClear = true;
            if(stage[idx].first != -1)
            {
                s++;
                stage[idx].first = -1;
            }
            idx++;
        }
        if(!canClear)
        {
            cout << "Too Bad"; return 0;
        }
    }
    cout << ans;
    return 0;
}