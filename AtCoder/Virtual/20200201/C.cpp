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
    ll c;
    ll s;
    ll f;
};

Data D[505];

int main() {
    ll N;
    cin >> N;
    REP(i, N - 1) {
        cin >> D[i].c >> D[i].s >> D[i].f;
    }

    REP(i, N) {
        ll t = 0;
        FOR(j, N - 1, i) {
            t = std::max(t, D[j].s);
            ll a = t / D[j].f;
            ll b = t % D[j].f;
            if (b > 0)
                a++;
            t = a * D[j].f;
            t += D[j].c;
        }
        cout << t << endl;
    }
    return 0;
}