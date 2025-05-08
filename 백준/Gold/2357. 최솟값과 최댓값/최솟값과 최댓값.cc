#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

class SegmentTree
{
    private:
        int n;
        vector<pair<int,int>> tree;

        void build(const vector<int>& a, int idx, int start, int end)
        {
            if(start==end){
                tree[idx] = {a[end],a[end]};
            }
            else{
                int mid = (start+end)/2;
                build(a, idx*2, start, mid); //왼쪽
                build(a, idx*2+1, mid+1, end); //오른쪽

                //연산
                tree[idx] = {min(tree[2*idx].first, tree[2*idx+1].first), max(tree[2*idx].second, tree[2*idx+1].second)};
            }
        }

        pair<int, int> query(int idx, int start, int end, int left, int right)
        {
            //범위 밖
            if(left > end || right < start){
                return {1'000'000'001, 0};
            }
            //범위 완전 포함
            if(left <= start && right >= end){
                return tree[idx];
            }
            int mid = (start+end)/2;

            auto le = query(2*idx, start, mid, left, right);
            auto ri = query(2*idx+1, mid+1, end, left, right);

            return {min(le.first, ri.first), max(le.second, ri.second)};
        }

    public:
        SegmentTree(const vector<int>& a)
        {
            n = a.size();
            tree.resize(4*n);
            build(a, 1, 0, n-1);
        }

        pair<int, int> query(int left, int right)
        {
            return query(1, 0, n-1, left, right);
        }      
};

signed main()
{
    FASTIO;
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i<n; i++) cin >> v[i];
    SegmentTree seg(v);

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        auto ans = seg.query(a-1,b-1);
        cout << ans.first << " " << ans.second <<"\n";
    }
    
    return 0;
}