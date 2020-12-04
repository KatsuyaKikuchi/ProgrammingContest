#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    memset(A, 0, sizeof(A));
    REP(i, M) {
        ll x;
        cin >> x;
        ll ok = N, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[mid] < x)
                ok = mid;
            else
                ng = mid;
        }
        if (ok == N)
            cout << -1 << endl;
        else {
            cout << ok + 1 << endl;
            A[ok] = x;
        }
    }
    return 0;
}