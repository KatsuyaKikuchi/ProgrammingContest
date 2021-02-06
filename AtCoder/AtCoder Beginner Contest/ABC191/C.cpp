#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    ll ans = 0;
    FOR(j, W - 1, 1) {
        {
            ll n = 0;
            REP(i, H) {
                if (S[i][j] == '#') {
                    if (S[i][j - 1] == '.') {
                        n = 1;
                    }
                    else {
                        ans += n;
                        n = 0;
                    }
                }
                else if (S[i][j] == '.') {
                    ans += n;
                    n = 0;
                }
            }
        }
        {
            ll n = 0;
            REP(i, H) {
                if (S[i][j] == '#') {
                    if (S[i][j + 1] == '.') {
                        n = 1;
                    }
                    else {
                        ans += n;
                        n = 0;
                    }
                }
                else if (S[i][j] == '.') {
                    ans += n;
                    n = 0;
                }
            }
        }
    }
    FOR(i, H - 1, 1) {
        {
            ll n = 0;
            REP(j, W) {
                if (S[i][j] == '#') {
                    if (S[i + 1][j] == '.') {
                        n = 1;
                    }
                    else {
                        ans += n;
                        n = 0;
                    }
                }
                else {
                    ans += n;
                    n = 0;
                }
            }
        }
        {
            ll n = 0;
            REP(j, W) {
                if (S[i][j] == '#') {
                    if (S[i - 1][j] == '.') {
                        n = 1;
                    }
                    else {
                        ans += n;
                        n = 0;
                    }
                }
                else {
                    ans += n;
                    n = 0;
                }
            }
        }
    }
#if false
    {
        ll p = -1;
        REP(j, W) {
            ll h = -1;
            REP(i, H) {
                if (S[i][j] == '#') {
                    h = i;
                    break;
                }
            }
            if (h < 0)
                continue;
            if (p != h)
                ans++;
            p = h;
        }
    }
    {
        ll p = -1;
        REP(j, W) {
            ll h = -1;
            for (ll i = H - 1; i >= 0; --i) {
                if (S[i][j] == '#') {
                    h = i;
                    break;
                }
            }
            if (h < 0)
                continue;
            if (p != h)
                ans++;
            p = h;
        }
    }
    {
        ll p = -1;
        REP(i, H) {
            ll w = -1;
            REP(j, W) {
                if (S[i][j] == '#') {
                    w = j;
                    break;
                }
            }
            if (w < 0)
                continue;
            if (p != w)
                ans++;
            p = w;
        }
    }
    {
        ll p = -1;
        REP(i, H) {
            ll w = -1;
            for (ll j = W - 1; j >= 0; --j) {
                if (S[i][j] == '#') {
                    w = j;
                    break;
                }
            }
            if (w < 0)
                continue;
            if (p != w)
                ans++;
            p = w;
        }
    }
#endif
    cout << ans << endl;
    return 0;
}