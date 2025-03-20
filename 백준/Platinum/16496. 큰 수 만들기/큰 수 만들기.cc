#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
bool flag = true;

bool compare(string f, string s)
{
    return f+s>s+f;
}

int main(){
    cin>>n;
    vector<string> arr(n);
    for(auto &e : arr){
        cin >> e;
        if(e !="0") flag = false;
    }
    if(flag){
        cout << "0";
        return 0;
    }
    sort(arr.begin(),arr.end(),compare);
    for(auto e: arr) cout << e;
    
    return 0;
}