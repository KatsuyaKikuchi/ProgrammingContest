#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll A[100005];

bool check(ll m) {
    ll count = 0;
    REP(i, N) {
        count += (A[i] + m - 1) / m;
    }
    return count >= K + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }

    ll ok = 0, ng = INF;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    ok++;

    vector<ll> v;
    REP(i, N) {
        ll n = (A[i] + ok - 1) / ok;
        ll p = A[i] / n;
        ll m = A[i] - n * p;
        REP(j, n - m) {
            v.push_back(p);
        }
        REP(j, m) {
            v.push_back(p);
        }
    }

    ll ans = 0;
    REP(i, v.size()) {
        ans += v[i] * v[i];
    }
    cout << ans << endl;
    return 0;
}