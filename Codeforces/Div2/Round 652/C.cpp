#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> B(K);
    REP(i, K) {
        cin >> B[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll ret = 0;
    ll index = 0;
    sort(B.begin(), B.end(), greater<ll>());
    REP(i, K) {
        if (B[i] == 1)
            ret += 2LL * A[index++];
    }
    ll pi = N - 1;
    REP(i, K) {
        if (B[i] == 1)
            continue;
        ret += A[index++] + A[pi];
        pi -= (B[i] - 1);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}