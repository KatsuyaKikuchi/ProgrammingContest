#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A, B;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        if (a - b <= 0)
            A.push_back(pll(a, b));
        else
            B.push_back(pll(a, b));
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    ll n = 0;
    ll ans = 0;
    REP(i, A.size()) {
        ans = std::max(ans, n + A[i].first);
        n += A[i].first - A[i].second;
    }
    REP(i, B.size()) {
        n += B[i].first - B[i].second;
        swap(B[i].first, B[i].second);
    }
    sort(B.begin(), B.end(), [](pll a, pll b) { return a.first < b.first; });
    REP(i, B.size()) {
        ans = std::max(ans, n + B[i].first);
        n += B[i].first - B[i].second;
    }
    cout << ans << endl;

    return 0;
}