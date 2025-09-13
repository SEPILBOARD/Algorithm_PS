#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

struct Node
{
    Node *l, *r;
    ll v;
    Node(): l(nullptr), r(nullptr), v(0) {}
};

class pst {
private:
    int n;
    vector<int> arr;
    Node *root[100001];

    void build(Node *node, int l, int r)
    {
        if(l == r) {
            node->v = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        node->l = new Node();
        node->r = new Node();
        build(node->l, l, mid);
        build(node->r, mid+1, r);
        node->v = node->l->v + node->r->v;
    }

    void update(Node *prv, Node *cur, int l, int r, int point, int v)
    {
        if(l == r) {
            cur->v = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(point <= mid) {
            cur->l = new Node();
            cur->r = prv->r;
            update(prv->l, cur->l, l, mid, point, v);
        } else {
            cur->r = new Node();
            cur->l = prv->l;
            update(prv->r, cur->r, mid+1, r, point, v);
        }
        cur->v = cur->l->v + cur->r->v;
    }

    ll query(Node *node, int l, int r, int lp, int rp)
    {
        if(rp < l || r < lp) return 0;
        if(lp <= l && r <= rp) return node->v;
        int mid = (l + r) >> 1;
        return query(node->l, l, mid, lp, rp) + query(node->r, mid+1, r, lp, rp);
    }

public:
    pst(int _n, vector<int> &a): n(_n), arr(a) {
        root[0] = new Node();
        build(root[0], 1, n);
    }

    void update(int t, int point, int v) {
        root[t] = new Node();
        update(root[t-1], root[t], 1, n, point, v);
    }

    ll query(int t, int lp, int rp) {
        return query(root[t], 1, n, lp, rp);
    }
};


signed main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++) cin >> a[i];

    pst pst(n, a);
    
    int m;
    int t = 1;

    cin >> m;
    for(int q = 0; q<m; q++){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int i, v;
            cin >> i >> v;
            pst.update(t++, i, v);
        }
        else{
            int k, i, j;
            cin >> k >> i >> j;
            
            cout << pst.query(k, i, j) <<"\n";
        }
    }
    
    return 0;
}