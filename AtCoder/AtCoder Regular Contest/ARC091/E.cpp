#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[300005];

vector<ll> solve(ll N, ll A, ll B) {
    vector<ll> v;
    ll t = 0;
    while (v.size() < N) {
        if (N - t == A) {
            for (ll i = t + 1; i <= N; ++i) {
                v.push_back(i);
            }
            break;
        }
        for (ll i = std::min(N - (A - 1), t + B); i > t; --i) {
            v.push_back(i);
        }
        t = std::min(N - (A - 1), t + B);
        A--;
    }
    return v;
}

ll LIS(vector<ll> v) {
    ll n = v.size();
    REP(i, n + 1) {
        dp[i] = INF;
    }

    REP(i, n) {
        *lower_bound(dp, dp + n, v[i]) = v[i];
    }

    return lower_bound(dp, dp + n, INF) - dp;
}

ll LDS(vector<ll> v) {
    ll n = v.size();
    REP(i, n + 1) {
        dp[i] = 0;
    }

    REP(i, n) {
        ll ok = -1, ng = n;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (dp[mid] > v[i])
                ok = mid;
            else
                ng = mid;
        }
        dp[ng] = v[i];
    }
    REP(i, n + 1) {
        if (dp[i] == 0)
            return i;
    }
    return 0;
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> v = solve(N, A, B);

    if (A != LIS(v) || B != LDS(v)) {
        cout << -1 << endl;
    }
    else {
        REP(i, N) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}