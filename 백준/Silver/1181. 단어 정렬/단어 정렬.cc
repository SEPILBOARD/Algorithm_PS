#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;

struct compare
{
    bool operator()(const string& fs, const string& sc) const
    {
        if(fs.length() == sc.length())
            return fs < sc;
        return fs.length() < sc.length();
    }
};
set<string, compare> s;

int main()
{
    FASTIO;
    cin >> n;
    string st;
    for(int i = 0; i<n; i++){
        cin >> st;
        s.insert(st);
    }
    for(string str: s) cout << str <<"\n";
    return 0;
}