#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;

int hanoiNum(int n)
{
    if(n == 1) return 1;
    return 2*hanoiNum(n-1) + 1;
}

void hanoi(int n, int start, int use, int end)
{
    if(n == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }

    hanoi(n-1, start, end, use);
    cout << start << " " << end << "\n";
    hanoi(n-1, use, start, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    cout << hanoiNum(n) << "\n";
    hanoi(n, 1, 2, 3);

    return 0;
}