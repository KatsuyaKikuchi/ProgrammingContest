#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool A[15][15];

int main() {
    ll N, M;
    cin >> N >> M;
    memset(A, 0, sizeof(A));
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        A[x][y] = A[y][x] = true;
    }

    ll ans = 0;
    REP(bit, pow(2LL, N)) {
        vector<ll> v;
        REP(i, N) {
            if ((bit >> i) & 1)
                v.push_back(i);
        }

        bool f = true;
        REP(i, v.size()) {
            FOR(j, v.size(), i + 1) {
                if (!A[v[i]][v[j]])
                    f = false;
            }
        }
        if (f)
            ans = std::max(ans, (ll)v.size());
    }
    cout << ans << endl;
    return 0;
}