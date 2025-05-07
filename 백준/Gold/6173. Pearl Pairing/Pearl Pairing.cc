#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

struct Compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int n, c;
int cnt[100'001];

int main()
{
    FASTIO;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    
    cin >> n >> c;
    for(int i = 1; i<=c; i++){
        int e; cin >> e;
        pq.push({i, e});
    }

    while(pq.size()>=2){
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        cout << a.first << " " <<b.first<<"\n";

        if(a.second > 1){
            pq.push({a.first, a.second - 1});
        }
        if(b.second > 1){
            pq.push({b.first, b.second - 1});
        }
    }

    return 0;
}