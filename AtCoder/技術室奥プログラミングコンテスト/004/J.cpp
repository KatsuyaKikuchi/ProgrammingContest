#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[30];
ll B[30];

int main() {
    ll N, M;
    cin >> N >> M;
    ll sa = 0;
    REP(i, N) {
        cin >> A[i];
        sa += A[i];
    }
    ll sb = 0;
    REP(i, M) {
        cin >> B[i];
        sb += B[i];
    }

    vector<ll> v;
    FOR(i, pow(2LL, M) - 1, 1) {
        ll s = 0;
        REP(j, M) {
            if ((i >> j) & 1)
                s += B[j];
        }
        if (s <= sb - s)
            continue;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    double ans = 0;
    FOR(i, pow(2LL, N) - 1, 1) {
        ll s = 0;
        REP(j, N) {
            if ((i >> j) & 1)
                s += A[j];
        }
        if (s <= sa - s)
            continue;

        ll n = 0;
        {
            ll ok = -1, ng = v.size();
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (v[mid] < s)
                    ok = mid;
                else
                    ng = mid;
            }
            n += ok + 1;
        }
        {
            ll ok = v.size() , ng = -1;
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (sb - v[mid] < sa - s)
                    ok = mid;
                else
                    ng = mid;
            }
            n -= ok;
        }
        ans = std::max(ans, (double) std::max(n, 0LL) / (double) v.size());
    }
    cout << OF64 << ans << endl;
    return 0;
}