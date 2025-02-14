#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, q;
int p[100001];
vector<pair<pair<int, int>,int>> v;

struct cmp {
    bool operator()(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        return a.first.first > b.first.first;
    }
};


int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y) p[y] = x;
}

int main()
{
    FASTIO;
    cin >> n >> q;
      priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
    for(int i = 1; i<= n; i++){
        int x1, x2, y; cin >> x1 >> x2 >> y;
        pq.push({{x1, x2}, i});
    }
    
    while(!pq.empty()){
        bool flag = true;
        auto pqt = pq.top();
        pq.pop();
        p[pqt.second] = pqt.second;
        for(int i = 0; i<v.size(); i++){
            if(pqt.first.first <= v[i].first.second){
                flag = false;
                v[i].first.second = max(v[i].first.second, pqt.first.second);
                Union(v[i].second, pqt.second);
                break;
            }
        }
        if(flag){
            v.push_back({{pqt.first.first, pqt.first.second}, pqt.second});
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        if(Find(a) == Find(b)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}