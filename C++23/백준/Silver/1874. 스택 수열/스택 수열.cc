#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
stack<int> stk;

signed main()
{
    FASTIO;
    
    cin >> n;
    stk.push(0);

    int num = 1;
    vector<char> ans;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;

        if(x<stk.top()){
            cout << "NO";
            return 0;
        }

        while(stk.top()<x){
            stk.push(num);
            num++;
            ans.push_back('+');
        }

        stk.pop();
        ans.push_back('-');
    }

    for(char c: ans){
        cout << c <<"\n";
    }

    return 0;
}