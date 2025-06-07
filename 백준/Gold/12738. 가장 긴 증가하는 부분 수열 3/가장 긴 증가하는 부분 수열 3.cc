#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1'000'001];
vector<int> l;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];

    l.push_back(-1987654321);
    for(int i = 0; i<n; i++){
        if(a[i]>l.back()){
            l.push_back(a[i]);
        }
        else{
            int idx = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
            l[idx] = a[i];
        }
    }
    cout << l.size()-1;
    return 0;
}