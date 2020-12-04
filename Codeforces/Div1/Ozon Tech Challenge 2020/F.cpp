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

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    {
        ll g = A[0];
        REP(i, N) {
            g = gcd(A[i], g);
        }
        if (g > 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans += (A[i] % 2);
    }

    vector<ll> v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return 0;
}