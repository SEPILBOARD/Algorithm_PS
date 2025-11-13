#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

struct Node
{
    int val;
    Node *l;
    Node *r;
};

Node node[10'001];

void insert(Node &cur, Node &ins)
{
    if(cur.val > ins.val){
        if(cur.l == NULL) cur.l = &ins;
        else insert(*cur.l, ins);
    }

    else{
        if(cur.r == NULL) cur.r = &ins;
        else insert(*cur.r, ins);
    }
}

void post(const Node &cur)
{
    if(cur.l != NULL) post(*cur.l);
    if(cur.r != NULL) post(*cur.r);
    cout << cur.val <<"\n";
}

signed main()
{
    FASTIO;
    
    int x;
    cin >> x;
    node[0].val = x;

    int idx = 1;
    while(cin >> x){
        node[idx].val = x;
        insert(node[0], node[idx]);
        idx++;
    }

    post(node[0]);
    return 0;
}   