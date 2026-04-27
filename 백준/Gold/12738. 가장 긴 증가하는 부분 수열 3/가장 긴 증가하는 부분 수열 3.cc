#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

class Seg
{
    private:
        int n;
        vector<int> tree;

        void upd(int node, int start, int end, int point, int val)
        {
            if(point<start || end<point) return;
            if(start==end){
                tree[node] = val;
                return;
            };

            int mid = start+end>>1;
            upd(2*node, start, mid, point, val);
            upd(2*node+1, mid+1, end, point, val);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }   

        int qry(int node, int start, int end, int l, int r)
        {
            if(end<l || r<start) return 0;
            if(l<=start && end<=r) return tree[node];

            int mid = start+end>>1;
            int lv = qry(2*node, start, mid, l, r);
            int rv = qry(2*node+1, mid+1, end, l, r);

            return max(lv, rv);
        }

    public:
        Seg(int n)
        {
            this->n = n;
            tree.resize(4*n, 0);
        }

        void upd(int p, int v) { upd(1, 0, n, p, v); }
        int qry(int l, int r) {return qry(1, 0, n, l, r);}
};

vector<int> itov;
inline int vtoi(int v) { return lower_bound(itov.begin(), itov.end(), v)-itov.begin(); }


signed main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> a(n);
    itov.resize(n);

    for(int i = 0; i<n; i++){
        cin >> a[i];
        itov[i] = a[i];
    }

    sort(itov.begin(), itov.end());
    itov.erase(unique(itov.begin(), itov.end()), itov.end());

    Seg dp(n);
    int ans = 0;
    for(int i = 0; i<n; i++){
        int idx = vtoi(a[i]);
        int mx = dp.qry(0, idx-1);
        dp.upd(idx, mx+1);

        ans = max(ans, mx+1);
    }
    cout << ans;

    return 0;
}