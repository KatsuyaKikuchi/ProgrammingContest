#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int S[200005][205];

ll solve(vector<ll> &A) {
    ll N = A.size();
    ll max = 0;
    REP(i, N) {
        max = std::max(A[i], max);
    }
    REP(i, N + 1) {
        REP(j, max + 1) {
            S[i][j] = 0;
        }
    }

    REP(i, N) {
        S[i][A[i]]++;
        REP(j, max + 1) {
            S[i + 1][j] += S[i][j];
        }
    }

    int ret = 0;
    REP(i, max + 1) {
        ret = std::max(ret, S[N - 1][i]);
    }

    REP(i, N) {
        ll a = A[i];
        int n = S[i][a];

        ll ok = 0, ng = N;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (S[N][a] - S[mid][a] >= n)
                ok = mid;
            else
                ng = mid;
        }

        if (ok <= i)
            continue;

        int m = 0;
        REP(j, max + 1) {
            m = std::max(S[ok][j] - S[i][j], m);
        }

        ret = std::max(ret, m + n * 2);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }

        cout << solve(A) << endl;
    }
    return 0;
}