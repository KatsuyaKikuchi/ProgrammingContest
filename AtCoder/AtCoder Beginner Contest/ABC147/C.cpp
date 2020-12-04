#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    vector<pll> x;
};

Data A[30];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        REP(j, a) {
            ll x, y;
            cin >> x >> y;
            x--;
            A[i].x.push_back(pll(x, y));
        }
    }

    ll p = pow(2, N);
    ll max = 0;
    REP(n, p) {
        bool exist = true;
        REP(i, N) {
            if (((n >> i) & 1) == 0)
                continue;

            REP(j, A[i].x.size()) {
                pll t = A[i].x[j];
                if (((n >> t.first) & 1) != t.second) {
                    exist = false;
                    break;
                }
            }

            if (!exist)
                break;
        }

        if (!exist)
            continue;

        ll m = 0;
        REP(i, N) {
            m += ((n >> i) & 1);
        }
        max = std::max(max, m);
    }
    cout << max << endl;
    return 0;
}