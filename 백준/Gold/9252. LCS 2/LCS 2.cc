#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s1, s2;
int dp [1001][1001];

void bt(int i, int j)
{
    if(dp[i][j] == 0) return;
    if(s1[i-1] == s2[j-1]){
        bt(i-1, j-1);
        cout << s1[i-1];
    }
    else if(dp[i-1][j]==dp[i][j]) bt(i-1, j);
    else bt(i, j-1);
}

int main()
{
    FASTIO;
    cin >> s1 >> s2;
    for(int i = 1; i<=s1.length(); i++){
        for(int j = 1; j<=s2.length(); j++){
            if(s1[i-1] != s2[j-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            else dp[i][j] = dp[i-1][j-1]+1;
        }
    }
    cout << dp[s1.length()][s2.length()] <<"\n";
    bt(s1.length(), s2.length());
    return 0;
}