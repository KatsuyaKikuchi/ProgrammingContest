#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    std::multiset<ll> B;
    REP(i, M) {
        ll b;
        cin >> b;
        B.insert(b);
    }
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });

    ll ans = 0;
    REP(i, N) {
        ll s = A[i].first;
        auto it = B.lower_bound(s);
        if (it != B.end() && *it <= A[i].second) {
           // cout << *it << endl;
            B.erase(it);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}