#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1'000'000];
int b[1'000'000];
// map <int, int> vtoi;
set<int> s;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        a[i] = e;
        if(!s.count(e)){
            // cout << s.size() <<": " << e <<"\n";
            b[s.size()] = e;
            s.insert(e);
        }
    }
    sort(b, b+s.size());
    // for(int i = 0; i<n; i++){
    //     cout << b[i] <<", ";
    // }
    

    for(int i = 0; i<n; i++){
        cout << lower_bound(b, b+s.size(), a[i]) - b <<" ";
    }


    return 0;
}