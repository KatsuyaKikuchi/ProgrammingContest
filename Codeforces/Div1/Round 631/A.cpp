#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll A[100005];
ll B[100005];

bool solve() {
    ll left = N, right = N;
    vector<pll> v(M);
    for (ll i = M - 1; i >= 0; --i) {
        left = left - A[i];
        right = std::min(right - 1, N - A[i]);
        v[i] = pll(left, right);
    }
    if (left > 0 || right < 0)
        return false;

    ll m = 0;
    REP(i, M) {
        B[i] = std::min(std::max(m, v[i].first), v[i].second);
        m = B[i] + A[i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, M) {
        cin >> A[i];
    }

    if (solve()) {
        REP(i, M) {
            cout << B[i] + 1;
            if (i < M - 1)
                cout << " ";
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}