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
    ll N, M, L;
    cin >> N >> M >> L;

    ll P, Q, R;
    cin >> P >> Q >> R;

    ll ans = 0;
    {
        ll p = N / P;
        ll q = M / Q;
        ll r = L / R;
        ans = std::max(ans, p * q * r);
    }
    {
        ll p = N / P;
        ll q = M / R;
        ll r = L / Q;
        ans = std::max(ans, p * q * r);
    }
    {
        ll p = N / Q;
        ll q = M / P;
        ll r = L / R;
        ans = std::max(ans, p * q * r);
    }
    {
        ll p = N / Q;
        ll q = M / R;
        ll r = L / P;
        ans = std::max(ans, p * q * r);
    }
    {
        ll p = N / R;
        ll q = M / P;
        ll r = L / Q;
        ans = std::max(ans, p * q * r);
    }
    {
        ll p = N / R;
        ll q = M / Q;
        ll r = L / P;
        ans = std::max(ans, p * q * r);
    }
    cout << ans << endl;
    return 0;
}