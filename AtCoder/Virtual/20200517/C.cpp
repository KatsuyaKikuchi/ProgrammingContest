#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C, K;
    cin >> N >> C >> K;
    REP(i, N) {
        cin >> T[i];
    }
    sort(T, T + N);
    ll ans = 1;
    ll index = 0;
    REP(i, N) {
        if (T[index] + K < T[i] || i - index >= C) {
            ans++;
            index = i;
        }
    }

    cout << ans << endl;
    return 0;
}