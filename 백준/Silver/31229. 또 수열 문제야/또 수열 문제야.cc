#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int num = 1;

int main()
{
    FASTIO;
    int n; cin >> n;
    while(n--) cout << num <<" ", num+=2;

    return 0;
}