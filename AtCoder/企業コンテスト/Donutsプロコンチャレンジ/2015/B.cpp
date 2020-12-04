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
    ll s;
    vector<ll> v;
};
ll A[20];
Data D[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> D[i].s;
        ll n;
        cin >> n;
        REP(j, n) {
            ll a;
            cin >> a;
            D[i].v.push_back(a - 1);
        }
    }

    ll ans = 0;
    REP(b, pow(2LL, N)) {
        ll num = 0;
        ll score = 0;
        REP(i, N) {
            if (((b >> i) & 1) == 1) {
                score += A[i];
                num++;
            }
        }
        if (num != 9)
            continue;

        REP(i, M) {
            ll count = 0;
            REP(j, D[i].v.size()) {
                if ((b >> D[i].v[j]) & 1)
                    count++;
            }
            if (count >= 3)
                score += D[i].s;
        }
        ans = std::max(ans, score);
    }
    cout << ans << endl;
    return 0;
}