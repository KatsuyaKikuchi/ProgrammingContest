#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A) {
    ll N = A.size();
    ll k = 0;
    REP(i, N - 1) {
        ll d = A[i + 1] - A[i];
        if (d >= 0)
            continue;
        ll p = 0;
        d = abs(d);
        while (d > 0) {
            p++;
            d /= 2;
        }
        k = std::max(k, p);
        A[i + 1] = A[i];
    }
    return k;
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