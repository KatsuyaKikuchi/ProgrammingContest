#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[200005];
ll N, K;

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll solve() {
    vector<ll> A, B;
    bool z = false;
    REP(i, N) {
        if (T[i] == 0)
            z = true;
        else if (T[i] < 0)
            B.push_back(T[i]);
        else if (T[i] > 0)
            A.push_back(T[i]);
    }
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end());

    if (A.size() + B.size() < K)
        return 0;
    if (A.size() == 0) {
        if (K % 2 == 1) {
            if (z)
                return 0;
            ll ret = 1;
            ll index = B.size() - 1;
            REP(i, K) {
                ret = (ret * (MOD + B[index - i])) % MOD;
            }
            return ret;
        }
        {
            ll ret = 1;
            REP(i, K) {
                ret = (ret * (MOD + B[i])) % MOD;
            }
            return ret;
        }
    }

    if (A.size() + B.size() == K && B.size() % 2 == 1) {
        if (z)
            return 0;
        ll ret = 1;
        REP(i, A.size()) {
            ret = (ret * (A[i])) % MOD;
        }
        REP(i, B.size()) {
            ret = (ret * (MOD + B[i])) % MOD;
        }
        return ret;
    }

    //! プラスのやつからK個とる
    {
        ll ret = 1;
        stack<ll> s;
        ll num = K;
        if (A.size() < K) {
            num = A.size();
            //! マイナスが偶数個になるように
            if ((K - num) % 2 == 1)
                num--;
        }
        REP(i, num) {
            ret = (ret * A[i]) % MOD;
            s.push(A[i]);
        }

        ll index = K - num;
        REP(i, index) {
            ret = (ret * (MOD + B[i])) % MOD;
        }

        while (s.size() >= 2 && index + 1 < B.size()) {
            ll t0 = s.top();
            s.pop();
            ll t1 = s.top();
            s.pop();

            ll s0 = B[index++];
            ll s1 = B[index++];

            if (t0 * t1 > s0 * s1)
                break;
            ret = (ret * modpow((t0 * t1) % MOD, MOD - 2)) % MOD;
            ret = (ret * ((s0 * s1) % MOD)) % MOD;
        }
        return ret;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) {
        cin >> T[i];
    }
    cout << solve() << endl;
    return 0;
}