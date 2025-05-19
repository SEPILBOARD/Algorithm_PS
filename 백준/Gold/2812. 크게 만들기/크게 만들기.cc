#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
vector<char> ans;

int main()
{
    FASTIO;
    cin >> n >> k;
    char c; cin >> c;
    ans.push_back(c);
    int curk = k;
    for(int i = 1; i<n; i++){
        cin >> c;
        if(curk>0 && ans.back() < c){
            while(curk>0 && ans.size()){
                if(ans.back() >= c) break;
                ans.pop_back();
                curk--;
            }
        }
        ans.push_back(c);
    }
    for(int i = 0; i<n-k; i++) cout << ans[i];
    return 0;
}