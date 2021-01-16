#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll l, r, x;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Data> D(M);
    REP(i, M) {
        cin >> D[i].l >> D[i].r >> D[i].x;
        D[i].l--;
    }

    ll ans = -1;
    REP(bit, pow(2LL, N)) {
        bool e = true;
        REP(i, M) {
            ll n = 0;
            FOR(b, D[i].r, D[i].l) {
                if ((bit >> b) & 1)
                    n++;
            }
            if (n != D[i].x) {
                e = false;
                break;
            }
        }
        if (!e)
            continue;
        ll cnt = 0;
        REP(i, N) {
            if ((bit >> i) & 1)
                cnt++;
        }
        ans = std::max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}