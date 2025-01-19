#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
vector<int> arr;
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int in; cin >> in;
        arr.push_back(in);
        dp[in] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(arr[j]<arr[i])
            {
                dp[arr[i]] = max(dp[arr[i]], dp[arr[j]]+1);
            }
        }
    }

    int ans =0;
    for(int i =0; i<1001; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}