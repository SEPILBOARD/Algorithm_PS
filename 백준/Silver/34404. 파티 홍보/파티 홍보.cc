    #include <bits/stdc++.h>
    #define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    using namespace std;
    typedef long long ll;

    int n;
    tuple<ll, ll, ll, ll> xypq[1'001];
    ll a, b;

    signed main()
    {
        FASTIO;
        cin >> n;
        for(int i = 0; i<n; i++){
            ll x, y, p, q;
            cin >> x >> y >> p >> q;
            xypq[i] = {x, y, p, q};
        }
        cin >> a >> b;

        int ans = 0;
        for(int i = 0; i<n; i++){
            auto[x, y, p, q] = xypq[i];
            long double midY = (y+q)/2.0;
            long double fmidX = a*((x+p)/2.0) + b;
            if(midY>fmidX) ans++;
        }

        cout << ans;
        return 0;
    }