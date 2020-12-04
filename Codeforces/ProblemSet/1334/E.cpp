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
    ll D;
    cin >> D;
    vector<ll> p;
    ll d = D;
    for (ll i = 2; i * i <= D; ++i) {
        if (d <= 1)
            break;
        if (d % i != 0)
            continue;
        p.push_back(i);
        while (d % i == 0)
            d /= i;
    }

    if (d > 1)
        p.push_back(d);

    vector<ll> v;
    for (ll i = 1; i * i < D; ++i) {
        if (D % i == 0) {
            v.push_back(i);
            v.push_back(D / i);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << endl;
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll a, b;
        cin >> a >> b;
    }

    return 0;
}