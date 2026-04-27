#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;

signed main()
{
    FASTIO;
    cin >> n;
    
    for(int i = 0; i<2*n; i++){
        for(int j = 1; j<2*n-i; j++){
            cout << " ";
        }
        cout << "*";
        for(int j = 0; j<=i; j++){
            cout << " ";
        }

        if(i<n){
            for(int j = 1; j<n-i; j++){
                cout << " ";
            }
            cout << "* ";
            for(int j = 0; j<2*i; j++){
                cout << " ";
            }
            cout << "*";
            for(int j = 1; j<n-i; j++){
                cout << " ";
            }
        }
        else{
            for(int j = 0; j<i-n; j++){
                cout << " ";
            }
            cout << "*";
            for(int j = 1; j<2*(2*n-i); j++){
                cout << " ";
            }
            cout << "*";
            for(int j = 0; j<i-n; j++){
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}