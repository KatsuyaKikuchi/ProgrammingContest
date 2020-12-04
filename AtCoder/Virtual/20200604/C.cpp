#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    A.push_back(X);
    sort(A.begin(), A.end());

    ll ans = A[1] - A[0];
    REP(i, N) {
        ans = gcd(ans, A[i + 1] - A[i]);
    }
    cout << ans << endl;
    return 0;
}