#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18 + 5;

ll N, K;
vector<ll> A, B;

bool check(ll m) {
    ll sum = 0;
    //! A*Bの中で数える
    REP(i, A.size()) {
        ll a = A[i];
        ll ok = -1, ng = B.size();
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (a * B[mid] <= m)
                ok = mid;
            else
                ng = mid;
        }
        sum += ok + 1;
    }

    //! A*Aの中で考える
    REP(i, A.size()) {
        ll ok = i, ng = A.size();
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[i] * A[mid] <= m)
                ok = mid;
            else
                ng = mid;
        }
        sum += ok - i;
    }

    //! B*B
    REP(i, B.size()) {
        ll ok = B.size(), ng = i;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (B[i] * B[mid] <= m)
                ok = mid;
            else
                ng = mid;
        }
        sum += B.size() - ok;
    }

    return sum >= K;
}

int main() {
    cin >> N >> K;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a > 0)
            A.push_back(a);
        else
            B.push_back(a);
    }
    sort(A.begin(), A.end(), [](ll a, ll b) { return a < b; });
    sort(B.begin(), B.end(), [](ll a, ll b) { return a < b; });
    ll ans = INF, ng = -INF;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}