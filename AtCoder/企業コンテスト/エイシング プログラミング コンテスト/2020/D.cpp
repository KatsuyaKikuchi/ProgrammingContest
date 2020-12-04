#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
string X;
ll cnt;

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1) {
            ret = (ret * p) % mod;
        }
        p = (p * p) % mod;
        r /= 2;
    }

    return ret % mod;
}

ll np = 0, nm = 0;

ll calc(ll num) {
    ll b = 0;
    ll ret = num;
    while (num > 0) {
        if (num & 1)
            b++;
        num >>= 1LL;
    }
    return ret % b;
}

ll solve(ll n) {
    if (X[n] == '1') {
        //! マイナス
        if (cnt == 1)
            return 0;
        ll num = (cnt - 1 + nm - modpow(2LL, N - 1 - n, cnt - 1)) % (cnt - 1);

        ll ret = 1;
        while (num > 0) {
            ret++;
            num = calc(num);
        }
        return ret;
    }

    {
        ll num = (np + modpow(2LL, N - 1 - n, cnt + 1)) % (cnt + 1);
        ll ret = 1;
        while (num > 0) {
            ret++;
            num = calc(num);
        }
        return ret;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> X;
    cnt = 0;
    REP(i, N) {
        if (X[i] == '1')
            cnt++;
    }
    np = 0, nm = 0;
    REP(i, N) {
        if (X[N - 1 - i] == '1') {
            np = (np + modpow(2, i, cnt + 1)) % (cnt + 1);
            if (cnt > 1) {
                nm = (nm + modpow(2, i, cnt - 1)) % (cnt - 1);
            }
        }
    }

    REP(i, N) {
        cout << solve(i) << endl;
    }

    return 0;
}