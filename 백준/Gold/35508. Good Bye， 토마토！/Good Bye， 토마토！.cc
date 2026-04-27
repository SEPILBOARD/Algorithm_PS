#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

class Seg
{
    private:
        int n;
        vector<int> tree;

        void upd(int node, int start, int end, int idx, int val)
        {
            if(idx<start || end<idx) return;
            if(start == end){
                tree[node] = max(tree[node], val);
                return;
            }
            
            int mid = start+end>>1;
            upd(2*node, start, mid, idx, val);
            upd(2*node+1, mid+1, end, idx, val);

            tree[node] = max(tree[2*node], tree[2*node+1]);
        }

        int qry(int node, int start, int end, int left, int right)
        {
            if(end<left || right<start) return 0;
            if(left<=start && end<=right) return tree[node];

            int mid = start+end>>1;
            int l = qry(2*node, start, mid, left, right);
            int r = qry(2*node+1, mid+1, end, left, right);

            return max(l, r);
        }

    public:
        Seg(int n)
        {
            this->n = n;
            tree.resize(4*n, 0);
        }

        void upd(int idx, int val){upd(1, 1, n, idx, val);}
        int qry(int left, int right){return qry(1, 1, n, left, right);}
};

int n, d;
tuple<int, int, int> tab[200'001];

vector<int> itot;
int ttoi(int t){ return lower_bound(itot.begin(), itot.end(), t)-itot.begin()+1; }

signed main()
{
    FASTIO;
    cin >> n >> d;
    Seg aSeg(2*n);
    // Seg bSeg(n);

    for(int i = 0; i<n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        tab[i] = {t, a, b};

        itot.push_back(t);
        itot.push_back(d-t);
    }
    sort(itot.begin(), itot.end());
    itot.erase(unique(itot.begin(), itot.end()), itot.end());
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        auto[t, a, b] = tab[i];

        ans = max(ans, a+b);

        aSeg.upd(ttoi(t), a);
    }

    for(int i = 0; i<n; i++){
        auto[t, a, b] = tab[i];

        if(t>=d) continue;
        ans = max(ans, b+aSeg.qry(1, ttoi(d-t)));
    }

    cout << ans;

    return 0;
}