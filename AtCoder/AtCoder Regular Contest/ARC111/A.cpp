#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> junkan(ll N) {
    ll m = 1;
    ll s = 0;
    ll t = 0;
    vector<ll> v;
    map<ll, bool> mp;
    while (true) {
        if (mp[m])
            break;
        v.push_back(m * 10 / N);
        mp[m] = true;
        m = (m * 10LL) % N;
        if (m == 0)
            break;
    }
    return v;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    auto v = junkan(M);
    ll s = 0;
    REP(i, v.size()) {
        if (v[i] != 0) {
            s = i;
            break;
        }
    }
#if true
    REP(i, N) {
        ll a = pow(10, i + 1);
        ll b = a / M;
        ll c = b % M;
        cout << a << " " << b << " " << c << endl;
    }
#endif

    return 0;
}