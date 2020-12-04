#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A, ll K) {
    ll N = A.size();
    vector<ll> v(2 * K + 5, 0), u(2 * K + 5, 0);
    REP(i, N / 2) {
        ll b = std::min(A[i], A[N - 1 - i]) + 1;
        ll t = std::max(A[i], A[N - 1 - i]) + K;
        v[b]++;
        v[t + 1]--;
        u[A[i] + A[N - 1 - i]]++;
    }

    REP(i, 2 * K) {
        v[i + 1] += v[i];
    }

    ll ret = INF;
    REP(i, 2 * K) {
        ll s = i + 1;

        ll c = (v[s] - u[s]) + 2 * (N / 2 - v[s]);
        ret = std::min(ret, c);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A, K) << endl;
    }
    return 0;
}