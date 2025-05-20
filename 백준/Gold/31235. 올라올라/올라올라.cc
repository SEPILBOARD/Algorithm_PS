#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1000001];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    int le = a[0];
    int k = 1;
    int cur_k = 1;
    for(int i = 1; i<n; i++){
        if(le<=a[i]){
            le = a[i];
            k = max(k, cur_k);
            cur_k = 1;
        }
        else{
            cur_k++;
        }
    }
    cout << max(k, cur_k);
    return 0;
}