#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i];
    }
    if (M == 0) {
        cout << 1 << endl;
        return 0;
    }
    sort(A, A + M);
    vector<ll> v;
    if (M > 0) {
        if (A[0] > 1)
            v.push_back(A[0] - 1);
    }
    REP(i, M - 1) {
        if (A[i + 1] - A[i] - 1 > 0)
            v.push_back(A[i + 1] - A[i] - 1);
    }
    if (M > 0) {
        if (N - A[M - 1] > 0)
            v.push_back(N - A[M - 1]);
    }

    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll x = v[0];
    REP(i, v.size()) {
        x = std::min(x, v[i]);
    }

#if false
    cout << x << endl;
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
#endif
    ll ans = 0;
    REP(i, v.size()) {
        ans += (v[i] + x - 1) / x;
    }
    cout << ans << endl;
    return 0;
}