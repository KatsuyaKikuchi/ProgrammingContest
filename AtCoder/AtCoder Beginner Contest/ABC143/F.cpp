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
    ll N;
    cin >> N;
    vector<ll> A(N + 1, 0);
    REP(i, N) {
        ll a;
        cin >> a;
        A[a]++;
    }
    sort(A.begin(), A.end(), greater<ll>());
    vector<ll> S(N + 1, 0);
    for (ll i = N - 1; i >= 0; --i) {
        S[i] += S[i + 1] + A[i];
    }
    vector<ll> ans(N + 1, 0);
    ll idx = 0;
    for (ll i = N; i > 0; --i) {
        while (A[idx] > i) {
            idx++;
        }
        ll len = idx + S[idx] / i;
        ans[len] = std::max(ans[len], i);
    }

    for (ll i = N; i > 0; --i) {
        ans[i - 1] = std::max(ans[i], ans[i - 1]);
    }
    REP(i, N) {
        cout << ans[i + 1] << endl;
    }

    return 0;
}