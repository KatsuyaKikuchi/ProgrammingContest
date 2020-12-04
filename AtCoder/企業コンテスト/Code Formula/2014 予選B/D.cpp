#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v(N);
    REP(i, N) {
        cin >> v[i];
    }
    ll ans = 1;
    ll p = 1;
    ll index = 0;
    ll s = 0;
    while (index < v.size()) {
        s = (s + (v[index] % 10) * p) % MOD;
        p = (p * 10LL) % MOD;
        if (v[index] <= 9) {
            ans = (ans * (s + 1LL)) % MOD;
            p = 1;
            s = 0;
        }
        ll t = v[index] / 10;
        if (t > 0) {
            if (index + 1 >= v.size())
                v.push_back(t);
            else
                v[index + 1] += t;
        }
        index++;
    }
    cout << (ans - 1 + MOD) % MOD << endl;
    return 0;
}