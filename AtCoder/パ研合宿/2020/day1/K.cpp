#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll S = 0;
    REP(i, N) {
        cin >> A[i];
        S += A[i];
    }
    vector<ll> v(S + 1, 0);
    REP(i, S) {
        ll x = i + 1;
        ll s = 0;
        ll n = 0;
        REP(j, N) {
            s += A[j];
            if (s % x == 0) {
                n++;
                s = 0;
            }
        }
        if (s != 0)
            continue;
        v[x] = std::max(n, v[x]);
    }
    for (ll i = S - 1; i >= 0; --i) {
        v[i] = std::max(v[i + 1], v[i]);
    }
    ll idx = S;
    REP(i, N) {
        while (v[idx] < i + 1)
            idx--;
        cout << idx << endl;
    }

    return 0;
}