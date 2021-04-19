#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &X, const vector<pll> &A) {
    sort(X.begin(), X.end());
    ll M = X.size();
    ll N = A.size();
    vector<bool> used(M, false);
    ll ret = 0;
    REP(i, N) {
        REP(j, M) {
            if (used[j])
                continue;
            if (X[j] < A[i].first)
                continue;
            ret += A[i].second;
            used[j] = true;
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<ll> X(M);
    REP(i, M) {
        cin >> X[i];
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.second > b.second; });

    REP(_, Q) {
        ll L, R;
        cin >> L >> R;
        L--;
        R--;
        vector<ll> x;
        REP(i, M) {
            if (L <= i && i <= R)
                continue;
            x.push_back(X[i]);
        }
        cout << solve(x, A) << endl;
    }
    return 0;
}