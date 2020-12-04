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
    ll K;
    cin >> K;
    vector<ll> v;
    v.push_back(0);
    REP(i, 9) {
        v.push_back(1 + i);
    }
    ll m = 10;
    while (v.size() <= K) {
        vector<ll> t;
        for (ll n = 1; n <= 9; ++n) {
            ll d = m * n;
            REP(i, v.size()) {
                ll a = v[i] / (m / 10);
                if (a > 0) {
                    if (abs(a - n) <= 1) {
                        t.push_back(d + v[i]);
                    }
                }
                else if (n == 1) {
                    ll b = v[i];
                    ll c = b % 10;
                    while (b > 0) {
                        c = b % 10;
                        b /= 10;
                    }
                    if (c == 1 || c == 0)
                        t.push_back(d + v[i]);
                }
            }
        }
        REP(i, t.size()) {
            v.push_back(t[i]);
        }
        m *= 10LL;
    }

    sort(v.begin(), v.end());
    cout << v[K] << endl;

    return 0;
}