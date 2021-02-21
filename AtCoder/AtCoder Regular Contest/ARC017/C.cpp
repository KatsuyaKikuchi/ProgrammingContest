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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    std::map<ll, ll> mp;
    ll n0 = N / 2;
    ll n1 = N - n0;
    REP(bit, pow(2LL, n0)) {
        ll s = 0;
        REP(i, n0) {
            if ((bit >> i) & 1)
                s += A[i];
        }
        mp[s]++;
    }

    ll ans = 0;
    REP(bit, pow(2LL, n1)) {
        ll s = 0;
        REP(i, n1) {
            if ((bit >> i) & 1)
                s += A[n0 + i];
        }
        ans += mp[X - s];
    }
    cout << ans << endl;

    return 0;
}