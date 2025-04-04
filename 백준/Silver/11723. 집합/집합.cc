#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

int main()
{
    FASTIO;
    int m, s;
    s = 0;
    cin >>  m;
    while(m--){
        char c; cin >> c;
        int x;
        if(c == 'a'){
            cin >> c;
            if(c == 'd'){
                cin >> c;
                cin >> x;
                s |= 1<<x;
            }
            else{
                cin >> c;
                s = (1<<21)-1;
            }
        }
        else if(c == 'r'){
            cin >> c; cin >> c; cin >> c; cin >> c; cin >> c;
            cin >> x;
            s &= ~(1<<x);
        }
        else if(c == 'c'){
            cin >> c; cin >> c; cin >> c; cin >> c;
            cin >> x;
            cout << !!(s&(1<<x)) <<"\n";
        }
        else if(c == 't'){
            cin >> c; cin >> c; cin >> c; cin >> c; cin >> c;
            cin >> x;
            s ^= 1<<x;
        }
        // empty
        else{
            cin >> c; cin >> c; cin >> c; cin >> c;
            s= 0;
        }
    }
    
    return 0;
}