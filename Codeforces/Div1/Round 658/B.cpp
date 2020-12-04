#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    REP(i, 2 * N) {
        cin >> A[i];
    }
    vector<bool> U(2 * N + 5, false);
    vector<ll> v;
    for (ll i = 2 * N; i > 0; --i) {
        if (U[i])
            continue;
        REP(j, A.size()) {
            if (A[j] != i)
                continue;

            ll num = 0;
            FOR(k, A.size(), j) {
                ll a = A[k];
                if (U[a])
                    continue;
                if (a > i)
                    continue;
                U[a] = true;
                num++;
            }
            v.push_back(num);
            break;
        }
    }

    vector<bool> dp0(N + 10, false);
    vector<bool> dp1(N + 10, false);
    dp0[0] = true;
    REP(i, v.size()) {
        REP(j, N) {
            dp1[j] = dp1[j] || dp0[j];
            if (!dp0[j])
                continue;
            ll nx = j + v[i];
            if (nx > N)
                continue;
            dp1[nx] = true;
        }
        swap(dp0, dp1);
    }

#if false
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
#endif
    return dp0[N];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;

    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}