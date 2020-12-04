#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

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
    std::multiset<ll> s;
    s.insert(-1);
    for (ll i = N - 1; i >= 0; --i) {
        auto it = s.upper_bound(A[i]);
        if (it == s.end()) {
            ans++;
            s.insert(A[i]);
            continue;
        }
        s.erase(it);
        s.insert(A[i]);
    }
    cout << ans << endl;
    return 0;
}