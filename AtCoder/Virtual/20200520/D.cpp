#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 100005;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    vector<pll> v0(MAX), v1(MAX);
    REP(i, MAX) {
        v0[i].second = i;
        v1[i].second = i;
    }
    for (ll i = 0; i < N; i += 2) {
        v0[A[i]].first++;
    }
    for (ll i = 1; i < N; i += 2) {
        v1[A[i]].first++;
    }
    ll a = (N + 1) / 2, b = N / 2;
    sort(v0.begin(), v0.end(), [](pll a, pll b) { return a.first > b.first; });
    sort(v1.begin(), v1.end(), [](pll a, pll b) { return a.first > b.first; });
    if (v0[0].second == v1[0].second)
        ans = std::min(a - v0[0].first + b - v1[1].first,
                       a - v0[1].first + b - v1[0].first);
    else
        ans = a - v0[0].first + b - v1[0].first;

    cout << ans << endl;
    return 0;
}