#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
class SegmentTree
{
    private:
        int n;
        vector<long long> tree;

        void build(const vector<int>& a, int idx, int start, int end)
        {
            if(start==end){
                tree[idx] = a[end];
            }
            else{
                int mid = (start+end)/2;
                build(a, idx*2, start, mid); //왼쪽
                build(a, idx*2+1, mid+1, end); //오른쪽

                //연산
                tree[idx] = tree[2*idx] + tree[2*idx+1];
            }
        }

        void update(int idx, int start, int end, int point, int value)
        {
            if(start == end){
                tree[idx] = value;
                return;
            }
            else{
                int mid = (start+end)/2;
                if(point <= mid) update(idx*2, start, mid, point, value);
                else update(idx*2+1, mid+1, end, point, value);

                //연산
                tree[idx] = tree[2*idx] + tree[2*idx+1];
            }
        }

        long long query(int idx, int start, int end, int left, int right)
        {
            //범위 밖
            if(left > end || right < start){
                return 0;
            }
            //범위 완전 포함
            if(left <= start && right >= end){
                return tree[idx];
            }
            int mid = (start+end)/2;

            return query(2*idx, start, mid, left, right) + query(2*idx+1, mid+1, end, left, right);
        }

    public:
        SegmentTree(const vector<int>& a)
        {
            n = a.size();
            tree.resize(4*n);
            build(a, 1, 0, n-1);
        }

        void update(int idx, int value)
        {   
            update(1, 0, n-1, idx, value);
        }

        long long query(int left, int right)
        {
            return query(1, 0, n-1, left, right);
        }      
};

signed main()
{
    FASTIO;
    int n, m; cin >> n >> m;
    vector<int> v(n);
    SegmentTree seg(v);

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a==1) seg.update(b-1,c);
        else{
            if(b < c) cout << seg.query(b-1,c-1) <<"\n";
            else cout << seg.query(c-1,b-1) <<"\n";
        }
    }
    
    return 0;
}