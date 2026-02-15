#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

class Seg
{
    private:
        int n;
        vector<int> tree;

        void init(int node, int start, int end, int val)
        {
            if(start == end){
                tree[node] = val;
                return;
            }

            int mid = start+end>>1;
            init(2*node, start, mid, val);
            init(2*node+1, mid+1, end, val);

            tree[node] = tree[2*node]+tree[2*node+1];
        }

        void upd(int node, int start, int end, int idx, int val)
        {
            if(idx<start || end<idx) return;
            if(start == end){
                tree[node] = val;
                return;
            }

            int mid = start+end>>1;
            upd(2*node, start, mid, idx, val);
            upd(2*node+1, mid+1, end, idx, val);

            tree[node] = tree[2*node]+tree[2*node+1];
        }

        int qry(int node, int start, int end, int cnt)
        {
            if(start == end) return start;
            int mid = start+end>>1;
            if(tree[2*node]>=cnt) return qry(2*node, start, mid, cnt);
            else return qry(2*node+1, mid+1, end, cnt-tree[2*node]);
        }

    public:
        Seg(int _n)
        {
            this->n = _n;
            tree.resize(4*n);
            init(1, 1, n, 1);
        }

        void upd(int idx, int val) {upd(1, 1, n, idx, val);}
        int qry(int cnt) {return qry(1, 1, n, cnt);}

};


signed main()
{
    FASTIO;
    int n, k;
    cin >> n >> k;

    Seg seg(n);
    int x = k;
    int p = n;

    cout << "<";
    for(int i = 0; i<n-1; i++){
        int ans = seg.qry(x);
        seg.upd(ans, 0);

        cout << ans <<", ";

        x = x-1+k;
        p -= 1;
        x = x%p;
        if(x == 0) x = p;
    }
    cout << seg.qry(x) <<">";
    
    return 0;
}