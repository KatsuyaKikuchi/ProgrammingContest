#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> R(N), B(N);
    REP(i, N) {
        cin >> R[i].first >> R[i].second;
    }
    REP(i, N) {
        cin >> B[i].first >> B[i].second;
    }
    sort(R.begin(), R.end(), [](pll a, pll b) { return a.first < b.first; });
    sort(B.begin(), B.end(), [](pll a, pll b) { return a.first < b.first; });
    ll ans = 0;
    vector<bool> used(N, false);
    REP(i, N) {
        ll mi = -1;
        REP(j, N) {
            if (used[j])
                continue;
            if (R[j].first > B[i].first)
                break;
            if (R[j].second > B[i].second)
                continue;
            if (mi < 0 || R[j].second > R[mi].second)
                mi = j;
        }
        if (mi >= 0) {
            ans++;
            used[mi] = true;
        }
    }
    cout << ans << endl;
    return 0;
}