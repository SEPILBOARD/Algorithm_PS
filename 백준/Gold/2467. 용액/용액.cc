#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int l[100000];
int r[3] ={1000000000, 1000000000, 2000000001};
int rr[3] ={1000000000, 1000000000, 2000000001};

bool check(int v)
{
    if(v<0) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0 ; i<n; i++)
    {
        cin >> l[i];
    }

    for(int i = 0; i<n; i++)
    {
        int lo = i; int hi = n;
        while(lo+1<hi)
        {
            int mid = (lo+hi)/2;
            int a = l[i]+l[mid];
            if(abs(a)<r[2])
            {   
                r[0] = l[i];
                r[1] = l[mid];
                r[2] = abs(a);
                
            }
            if(check(a)) lo = mid;
            else hi = mid;
        }
        if(r[2]<rr[2])
        {
            rr[0] = r[0];
            rr[1] = r[1];
            rr[2] = r[2];
        }
    }
    cout << r[0] << " " << r[1] << "\n";
    return 0;
}