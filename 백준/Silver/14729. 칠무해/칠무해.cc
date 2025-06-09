#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
float a[10'000'001];

int main()
{
    // FASTIO;
    cin >> n;
    for(int i= 0; i<n; i++) scanf("%f", &a[i]);
    sort(a, a+n);
    cout.precision(5);
    for(int i = 0; i<7; i++){
        int t = a[i];
        printf("%.3f\n", a[i]);
    }
    return 0;
}