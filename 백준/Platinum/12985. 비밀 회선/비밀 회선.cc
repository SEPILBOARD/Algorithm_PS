#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

struct Node
{
    ll x = 0;
    int cnt = 0;
};


class Seg
{
    private:
        int n;
        vector<Node> tree;

        void upd(int node, int start, int end, int idx)
        {
            if(idx<start || end<idx) return;
            if(start == end){
                tree[node].cnt++;
                tree[node].x += idx;
                return;
            }

            int mid = start+end>>1;
            upd(2*node, start, mid, idx);
            upd(2*node+1, mid+1, end, idx);
            
            tree[node].cnt = tree[2*node].cnt+tree[2*node+1].cnt;
            tree[node].x = tree[2*node].x+tree[2*node+1].x;
        }

        Node qry(int node, int start, int end, int left, int right)
        {
            if(end<left || right<start) return {0, 0};
            if(left<=start && end<=right) return tree[node];

            int mid = start+end>>1;
            Node l = qry(2*node, start, mid, left, right);
            Node r = qry(2*node+1, mid+1, end, left, right);

            return {l.x+r.x, l.cnt+r.cnt};
        }

    public:
        Seg(int n)
        {
            this->n = n;
            tree.resize(4*n);
        }

        void upd(int idx){upd(1, 0, n, idx);}
        Node qry(int l, int r) {return qry(1, 0, n, l, r);}

};

signed main()
{
    FASTIO;
    
    Seg seg(50'000);

    int n;
    cin >> n;

    vector<pair<int, int>> vx(n);
    for(int i = 0; i<n; i++){
        cin >> vx[i].first >> vx[i].second;
    }

    sort(vx.begin(), vx.end());

    ll ans = 0;
    for(int i = 0; i<n; i++){
        auto[V, X] = vx[i];
        Node l = seg.qry(0, X);
        Node r = seg.qry(X+1, 50'000);

        ans += (1LL*l.cnt*X - l.x)*V;
        ans += (r.x - 1LL*r.cnt*X)*V;

        seg.upd(X);
    }
    
    cout << ans;
    return 0;
}