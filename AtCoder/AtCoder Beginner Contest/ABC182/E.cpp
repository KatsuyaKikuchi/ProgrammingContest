#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[1505][1505];
ll C[1505][1505];
bool T[1505][1505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N, M;
    cin >> H >> W >> N >> M;
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(T, 0, sizeof(T));
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        B[a][b]++;
        C[a][b]++;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        T[a][b] = true;
    }

    REP(i, H) {
        REP(j, W) {
            if (j > 0)
                B[i][j] += B[i][j - 1];
            if (T[i][j])
                B[i][j] = 0;
        }
        for (ll j = W - 2; j >= 0; --j) {
            B[i][j] += B[i][j + 1];
            if (T[i][j])
                B[i][j] = 0;
        }
    }

    REP(j, W) {
        REP(i, H) {
            if (i > 0)
                C[i][j] += C[i - 1][j];
            if (T[i][j])
                C[i][j] = 0;
        }

        for (ll i = H - 2; i >= 0; --i) {
            C[i][j] += C[i + 1][j];
            if (T[i][j])
                C[i][j] = 0;
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (!T[i][j] && (B[i][j] > 0) || C[i][j] > 0)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}