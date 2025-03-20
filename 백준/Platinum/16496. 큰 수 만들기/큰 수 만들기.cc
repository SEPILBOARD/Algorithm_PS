#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
unsigned long long a[1000];
vector<int> r;

bool allZ = true;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i =0; i<n; i++)
    {
        cin >> a[i];
        if(a[i]) allZ = false;
    }

    if(allZ)
    {
        cout << 0;
        return 0;
    }
    
    for(int i =0; i<n; i++)
    {
        int c =0;
        while(c<i)
        {
            unsigned long long iLog = 1;
            if(r[c]) iLog = log10(r[c])+1;
            unsigned long long iFront = a[i] * pow(10, iLog) + r[c];

            unsigned long long cLog = 1;
            if(a[i]) cLog = log10(a[i])+1;
            unsigned long long cFront = r[c] * pow(10, cLog) + a[i];

            if(iFront > cFront)
            {
                r.insert(r.begin()+c, 1, a[i]);
                break;
            }
            else c++;
        }
        if(c==i)
        {
            r.push_back(a[i]);
        }
    }

    for(int k : r)
    {
        cout << k;
    }

    return 0;
}