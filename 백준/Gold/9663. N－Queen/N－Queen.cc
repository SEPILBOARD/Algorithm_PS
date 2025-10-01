#include <iostream>
#include <math.h>
using namespace std;

int N;
bool c[15][15];

int ans =0;

void Q(int ro)
{
    if(ro == N)
    {
        ans ++;
        return;
    }

    for(int co =0; co<N; co++)
    {
        bool canPos = true;
        for(int roUpp = ro-1; roUpp>=0; roUpp--)
        {
            int itv = ro - roUpp;
            if(c[roUpp][co]) 
            {
                canPos =false;
                break;
            }
            if(co-itv >=0)
            {
                if(c[roUpp][co-itv])
                {
                    canPos = false;
                    break;
                }
            }
            if(co+itv<N)
            {
                if(c[roUpp][co+itv])
                {
                    canPos = false;
                    break;
                }
            }
        }
        if(canPos)
        {
            c[ro][co] = true;
            Q(ro+1);
            c[ro][co] = false;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    Q(0);

    cout << ans;

    return 0;
}