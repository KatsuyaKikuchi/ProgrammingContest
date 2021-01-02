#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9 + 1;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());
    map<ll, bool> mp;
    ll ans = 0;
    REP(i, N) {
        ll x = A[i];
        bool e = true;
        while (x < INF) {
            if (mp[x]) {
                e = false;
                break;
            }
            mp[x] = true;
            x *= 2LL;
        }
        if (e)
            ans++;
    }
    cout << ans << endl;
    return 0;
}