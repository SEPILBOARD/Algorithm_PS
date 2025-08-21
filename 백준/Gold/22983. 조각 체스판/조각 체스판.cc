#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long result =0;
char C[3001][3001];
long long dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    result = n*m;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> C[i][j];
            dp[i][j] = 1;
        }
    }
 
    for(int i = 1; i<n; i++)
    {
        for(int j =1; j<m; j++)
        {
            if(C[i][j] == C[i-1][j-1] && C[i][j]!=C[i-1][j] && C[i][j] !=C[i][j-1]) 
            {
                long long add = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]); 
                result += add;
                dp[i][j] = add + 1;
            }
        }
    }
    cout << result;
}