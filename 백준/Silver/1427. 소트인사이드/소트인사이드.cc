#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;

int main()
{
    FASTIO;
    cin >> s;

    sort(s.begin(), s.end(), greater<>());
    cout << s;
    return 0;
}