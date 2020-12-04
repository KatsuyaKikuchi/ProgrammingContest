#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll N, vector<ll> &A) {
    ll s = 0;
    REP(i, A.size()) {
        s += A[i];
    }
    if (s < N)
        return -1;
    vector<ll> v(100, 0);
    REP(i, A.size()) {
        REP(j, v.size()) {
            if (((A[i] >> j) & 1) == 1) {
                v[j]++;
                break;
            }
        }
    }

    ll ans = 0;
    REP(i, 60) {
        if (((N >> i) & 1) == 1) {
            if (v[i] == 0) {
                ll ni = i;
                FOR(j, v.size(), i + 1) {
                    if (v[j] == 0)
                        continue;
                    ni = j;
                    break;
                }
                for (ll j = ni; j > i; --j) {
                    v[j]--;
                    v[j - 1] += 2;
                    ans++;
                }
            }
            v[i]--;
        }
        v[i + 1] += v[i] / 2;
    }
    return ans;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, M;
        cin >> N >> M;
        vector<ll> A(M);
        REP(i, M) {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }
    return 0;
}