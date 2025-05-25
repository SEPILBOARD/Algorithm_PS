#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int A[1000000];
long long int ans1, ans2 = 0;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> A[i];
    sort(A, A+n);
    int si = 0; int ei =n-1;
    
    if(n%2 == 1){
        int bf1 = A[n/2+1];
        while(si < ei){
            ans1 += abs(bf1-A[si]);
            bf1 = A[si]; si++;
            if(ei == n/2+1) ei--;
            ans1 += abs(bf1-A[ei]);
            bf1 = A[ei]; ei--;
        }

        int bf2 = A[n/2-1];
        si = 0; ei =n-1;
        while(ei > si){
            ans2 += abs(bf2-A[ei]);
            bf2 = A[ei]; ei--;
            if(si == n/2-1) si++;
            ans2 += abs(bf2-A[si]);
            bf2 = A[si]; si++;
        }
        cout << max(ans1, ans2);
    }
    else{
        int bf = A[n/2];
        while(si != n/2){
            ans1 += abs(bf-A[si]);
            bf = A[si]; si++;
            if(si == n/2) break;

            ans1 += abs(bf-A[ei]);
            bf = A[ei]; ei--;
        }
        cout << ans1;
    }

    return 0;
}