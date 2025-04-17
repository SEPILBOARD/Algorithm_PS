#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int in[100'001];
int inidx[100'001];
int post[100'001];

void recu(int isidx, int ieidx, int psidx, int peidx)
{
    if(ieidx < isidx || peidx < psidx) return;
    cout << post[peidx] <<" ";
    int ridx = inidx[post[peidx]];
    int len =  ridx - isidx;
    recu(isidx, ridx-1, psidx, psidx+len-1);
    recu(ridx+1, ieidx, psidx+len, peidx-1);
}

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> in[i];
        inidx[in[i]] = i;
    }
    for(int i = 1; i<=n; i++) cin >> post[i];
    recu(1, n, 1, n);    
    return 0;
}