#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll a, ll b, ll c) {
    vector<ll> v;
    FOR(i, pow(2, 3), 1) {
        v.push_back(i);
    }
    vector<ll> u;
    REP(i, v.size()) {
        u.push_back(i);
    }

    ll max = 0;
    do {
        ll d[3] = {a, b, c};
        ll m = 0;
        REP(i, u.size()) {
            bool e = true;
            REP(j, 3) {
                if ((v[u[i]] >> j) & 1) {
                    if (d[j] == 0)
                        e = false;
                }
            }
            if (e) {
                REP(j, 3) {
                    if ((v[u[i]] >> j) & 1) {
                        d[j]--;
                    }
                }
                m++;
            }
        }
        max = std::max(max, m);
    } while (next_permutation(u.begin(), u.end()));
    return max;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll A, B, C;
        cin >> A >> B >> C;
        cout << solve(A, B, C) << endl;
    }
    return 0;
}