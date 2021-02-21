#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll ans = N / gcd(N, M) * M;
    ll nd = ans / N, md = ans / M;
    ll n = 0, m = 0;
    while (n < N && m < M) {
        if (S[n] != T[m])
            ans = -1;
        n += md;
        m += nd;
    }
    cout << ans << endl;

    return 0;
}