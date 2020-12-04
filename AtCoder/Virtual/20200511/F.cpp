#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        a--;
        A[a] = i;
    }

    std::set<ll> s;
    s.insert(-1);
    s.insert(N);
    ll ans = 0;
    REP(i, N) {
        ll index = A[i];
        auto it = s.lower_bound(index);
        ll t = *it - index;
        it--;
        t *= index - *it;
        ans += (i + 1) * t;
        s.insert(index);
    }
    cout << ans << endl;
    return 0;
}