#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll D[55][55];
ll S[55][55];
ll A[2505];
ll M[55][55];

ll calc(ll x, ll y) {
    ll max = 0;
    REP(i, N) {
        REP(j, N) {
            ll nx = i + x - 1, ny = j + y - 1;
            nx = std::min(N, nx);
            ny = std::min(N, ny);

            ll s = S[nx][ny];
            if (i > 0)
                s -= S[i - 1][ny];
            if (j > 0)
                s -= S[nx][j - 1];
            if (i > 0 && j > 0)
                s += S[i - 1][j - 1];
            max = std::max(max, s);
        }
    }
    return max;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> D[i][j];
        }
    }

    memset(S, 0, sizeof(S));
    REP(i, N + 1) {
        REP(j, N + 1) {
            S[i][j] += D[i][j];
            S[i][j + 1] += S[i][j];
        }
    }

    REP(j, N + 1) {
        REP(i, N + 1) {
            S[i + 1][j] += S[i][j];
        }
    }

    memset(M, 0, sizeof(M));
    REP(x, N + 1) {
        REP(y, N + 1) {
            M[x + 1][y + 1] = calc(x + 1, y + 1);
        }
    }

    REP(i, N * N) {
        ll n = i + 1;
        ll max = 0;
        REP(j, n) {
            ll x = std::min(n / (j + 1), N);
            ll y = std::min(j + 1, N);
            max = std::max(max, M[x][y]);
        }
        A[n] = max;
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll n;
        cin >> n;
        cout << A[n] << endl;
    }
    return 0;
}