#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int x[3];
int y[3];

int main()
{
    FASTIO;
    for(int i = 0 ; i<3; i++){
        cin >> x[i] >> y[i];
    }

    if((y[1]-y[0])*(x[2]-x[1]) == (x[1]-x[0])*(y[2]-y[1]))
        cout << "WHERE IS MY CHICKEN?";
    else cout << "WINNER WINNER CHICKEN DINNER!";
    
    return 0;
}