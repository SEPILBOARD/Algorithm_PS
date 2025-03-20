#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ls;

int n;
int N[40];
int s;
long long result =0;

void sumLs(int index, int sum)
{
    if(index >= n/2)
    {
        ls.push_back(sum);
        return;
    }
    else
    {
        sumLs(index+1, sum);
        sumLs(index+1, sum+N[index]);
    }
}

void sumRs(int index, int sum)
{
    if(index >= n)
    {
        result += upper_bound(ls.begin(), ls.end(), s-sum) - lower_bound(ls.begin(), ls.end(), s-sum);
        return;
    }
    else
    {
        sumRs(index+1, sum);
        sumRs(index+1, sum+N[index]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>s;

    for(int i =0; i<n; i++)
    {
        cin >> N[i];
    }

    sumLs(0, 0);
    sort(ls.begin(),ls.end());
    sumRs(n/2,0);
    if(!s) result --;

    cout << result;
    return 0;
}