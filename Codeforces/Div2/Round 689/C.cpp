#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<ll, double> pld;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<pld> P(M);
    REP(i, M) {
        cin >> P[i].first >> P[i].second;
    }
    ll last = N;
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] - 1 != i)
            break;
        last = i;
    }
    if (last == 0)
        return 1;

    double p = 1;
    REP(i, M) {
        if (last <= P[i].first) {
            p *= (1.0 - P[i].second);
        }
    }
    return 1.0 - p;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << OF64 << solve() << endl;
    }
    return 0;
}