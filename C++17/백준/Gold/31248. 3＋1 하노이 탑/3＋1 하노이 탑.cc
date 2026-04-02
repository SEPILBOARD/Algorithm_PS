#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
char AS = 'A';

int ans =0;

void hanoiNum(int n, char start, char use, char end)
{
    if(n == 1)
    {
        ans ++;
        return;
    }

    hanoiNum(n-1, start, end, use);
    ans ++;
    hanoiNum(n-1, use, start, end);
}

void newHanoiNum(int n)
{
    if(n == 1)
    {
        ans ++;
        return;
    }
    else if(n==2)
    {
        ans +=3;
        return;
    }
    
    if(AS == 'A')
    {
        hanoiNum(n-2, 'A', 'B', 'C');
        AS = 'C';
        ans +=3;
    }
    else
    {
        hanoiNum(n-2, 'C', 'B', 'A');
        AS = 'A';
        ans +=3;
    }
    newHanoiNum(n-2);
}

void hanoi(int n, char start, char use, char end)
{
    if(n == 1)
    {
        cout << start << " " << end << "\n";
        // ans ++;
        return;
    }

    hanoi(n-1, start, end, use);
    cout << start << " " << end << "\n";
    // ans ++;
    hanoi(n-1, use, start, end);
}

void newHanoi(int n)
{
    if(n == 1)
    {
        cout << AS << " D\n";
        // ans ++;
        return;
    }
    else if(n==2)
    {
        cout << AS << " B\n";
        cout << AS << " D\n";
        cout << "B D\n";
        // ans +=3;
        return;
    }
    
    if(AS == 'A')
    {
        hanoi(n-2, 'A', 'B', 'C');
        AS = 'C';
        cout << "A B\n";
        cout << "A D\n";
        cout << "B D\n";
        // ans +=3;
    }
    else
    {
        hanoi(n-2, 'C', 'B', 'A');
        AS = 'A';
        cout << "C B\n";
        cout << "C D\n";
        cout << "B D\n";
        // ans +=3;
    }
    newHanoi(n-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    newHanoiNum(N);
    cout << ans <<"\n";
    AS = 'A';
    newHanoi(N);
    return 0;
}