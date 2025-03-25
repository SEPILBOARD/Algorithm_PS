#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> x;
int xScore[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i =0; i<n; i++)
    {
        x.push_back(vector<int>());
        int vl;
        cin >> vl;  x[i].push_back(vl);
        x[i].push_back(i);
    }

    sort(x.begin(), x.end());

    for(int i =0; i<n; i++)
    {
        for(int j = x[i][0] *2; j<=x[n-1][0]; j += x[i][0])
        {
            int lo=i, hi = n;
            while(lo+1 < hi)
            {
                int mid = (lo + hi)/2;
                if(x[mid][0] > j) hi = mid;
                else lo = mid;
            }
            if(j == x[lo][0])
            {
                xScore[x[i][1]] ++;
                xScore[x[lo][1]] --;
            }
        }
    }

    for(int i =0; i<n; i++)
    {
        cout << xScore[i] << " ";
    }

    return 0;
}