#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define B(x) (1<<x)

int sg[10] ={
    B(1)+B(2)+B(3)     +B(5)+B(6)+B(7), //0
              B(3)          +B(6)     , //1
    B(1)     +B(3)+B(4)+B(5)     +B(7), //2
    B(1)     +B(3)+B(4)     +B(6)+B(7), //3
         B(2)+B(3)+B(4)     +B(6)     , //4
    B(1)+B(2)     +B(4)     +B(6)+B(7), //5
    B(1)+B(2)     +B(4)+B(5)+B(6)+B(7), //6
    B(1)     +B(3)          +B(6)     , //7
    B(1)+B(2)+B(3)+B(4)+B(5)+B(6)+B(7), //8
    B(1)+B(2)+B(3)+B(4)     +B(6)+B(7), //9
};

int s;
string num;

signed main()
{
    FASTIO;
    cin >> s;
    cin >> num;
    int n = num.length();

    //1
    for(int i = 0; i<n; i++){
        cout << ' ';
        for(int j = 0; j<s; j++){
            cout << ((sg[num[i]-'0']&B(1)) ? '-':' ');
        }
        cout << "  ";
    }
    cout << "\n";
    
    //2 3
    for(int j = 0; j<s; j++){
        for(int i = 0; i<n; i++){
            cout << ((sg[num[i]-'0']&B(2)) ? '|':' ');
            for(int j = 0; j<s; j++) cout << ' ';
            cout << ((sg[num[i]-'0']&B(3)) ? "| ":"  ");
        }
        cout << "\n";
    }

    //4
    for(int i = 0; i<n; i++){
        cout << ' ';
        for(int j = 0; j<s; j++)
            cout << ((sg[num[i]-'0']&B(4)) ? '-':' ');
        cout << "  ";
    }
    cout << "\n";

    //5 6
    for(int j = 0; j<s; j++){
        for(int i = 0; i<n; i++){
            cout << ((sg[num[i]-'0']&B(5)) ? '|':' ');
            for(int j = 0; j<s; j++) cout << ' ';
            cout << ((sg[num[i]-'0']&B(6)) ? "| ":"  ");
        }
        cout << "\n";
    }

    //7
    for(int i = 0; i<n; i++){
        cout << ' ';
        for(int j = 0; j<s; j++)
            cout << ((sg[num[i]-'0']&B(7)) ? '-':' ');
        cout << "  ";
    }

    return 0;
}