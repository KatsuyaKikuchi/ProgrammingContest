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

void solve() {
    ll A, B, Q;
    cin >> A >> B >> Q;

    if (A > B)
        swap(A, B);
    ll g = A / gcd(A, B) * B;
    vector<ll> v(g + 1, 0);
    REP(i, g) {
        v[i + 1] += v[i];
        ll n = i + 1;
        if ((n % A) % B != (n % B) % A)
            v[i + 1]++;
    }

    vector<ll> ans(Q);
    REP(i, Q) {
        ll x, y;
        cin >> x >> y;

        ll xn = (x - 1) / g, yn = y / g;
        ll xm = (x - 1) % g, ym = y % g;

        ll sx = v[g] * xn + v[xm];
        ll sy = v[g] * yn + v[ym];
#if false
        for (ll j = x; j <= y; ++j) {
            cout << (j % A) % B << " " << (j % B) % A << endl;
        }
#endif
        ans[i] = sy - sx;
    }
    REP(i, Q) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}