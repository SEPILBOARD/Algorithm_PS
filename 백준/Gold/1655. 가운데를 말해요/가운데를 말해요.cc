#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, x;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<>> pq2;

signed main()
{
    FASTIO;
    cin >> n;

    {
        cin >> x;
        cout << x <<"\n";
        pq1.push(x);
    }

    if(n>=2){
        cin >> x;
        int a = pq1.top();
        if(x<a){
            pq2.push(a);
            pq1.pop();
            pq1.push(x);
        }
        else{
            pq2.push(x);
        }
        cout << pq1.top() <<"\n";
    }

    for(int i = 2; i<n; i++){
        cin >> x;
        int a = pq1.top();
        int b = pq2.top();

        if(pq1.size() == pq2.size()){
            if(b<x){
                pq1.push(b);
                pq2.pop();
                pq2.push(x);
            }
            else{
                pq1.push(x);
            }
        }
        else{
            if(x<a){
                pq2.push(a);
                pq1.pop();
                pq1.push(x);
            }
            else{
                pq2.push(x);
            }
        }
        cout << pq1.top() << "\n";
    }

    return 0;
}