#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = ((ll) 1e18) + 100LL;

ll K, N, M;
ll A[100005];
vector<ll> B;

// N*b - M*a>=-m となるような最小のbを求める
ll calc(ll a, ll m) {
    ll ok = M + 1, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * N - M * a >= -m)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

// N*b - M*a<=m となるような最大のbを求める
ll calc2(ll a, ll m) {
    ll ok = -1, ng = M + 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * N - M * a <= m)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

bool check(ll m) {
    ll sum = 0;
    REP(i, K) {
        B[i] = calc(A[i], m);
        if (B[i] == M + 1)
            return false;
        sum += B[i];
    }
    if (sum > M)
        return false;
    ll mm = M - sum;
    REP(i, K) {
        ll b = calc2(A[i], m);
        if (b == -1)
            return false;
        ll t = std::min(b - B[i], mm);
        mm -= t;
        B[i] += t;
    }
    return mm <= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> K >> N >> M;
    REP(i, K) {
        cin >> A[i];
    }
    B.resize(K);
    ll ok = INF, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    check(ok);
    REP(i, K) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}