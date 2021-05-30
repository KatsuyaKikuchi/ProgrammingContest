#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll A[805][805];
ll S[805][805];

bool check(ll mid) {
    memset(S, 0, sizeof(S));
    REP(i, N) {
        REP(j, N) {
            if (A[i][j] <= mid)
                S[i][j]++;
        }
    }
#if false
    REP(i, N) {
        REP(j, N) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
#endif
    REP(i, N + 1) {
        REP(j, N) {
            S[i][j + 1] += S[i][j];
        }
    }
    REP(j, N + 1) {
        REP(i, N) {
            S[i + 1][j] += S[i][j];
        }
    }

    ll m = ((K * K + 1) / 2);
    REP(i, N) {
        REP(j, N) {
            if (i + K > N || j + K > N)
                break;
            ll s = S[i + K - 1][j + K - 1];
            if (i > 0)
                s -= S[i - 1][j + K - 1];
            if (j > 0)
                s -= S[i + K - 1][j - 1];
            if (i > 0 && j > 0)
                s += S[i - 1][j - 1];
            // cout << s << endl;
            if (s >= m)
                return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }
#if true
    ll ans = INF, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }

    cout << ans << endl;
#else
    check(5);
#endif
    return 0;
}