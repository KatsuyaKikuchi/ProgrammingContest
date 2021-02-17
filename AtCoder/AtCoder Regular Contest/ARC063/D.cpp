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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll max = 0;
    T /= 2;
    ll min = INF;
    REP(i, N) {
        ll t = (A[i] - min);
        max = std::max(max, t);
        min = std::min(min, A[i]);
    }
    ll ans = 0;
    std::map<ll, ll> mp;
    REP(i, N) {
        if (mp.count(A[i] - max)) {
            ans++;
        }
        mp[A[i]]++;
    }
    cout << ans << endl;
    return 0;
}