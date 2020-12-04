#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> S(N, vector<ll>(M));
    REP(i, N) {
        REP(j, M) {
            cin >> S[i][j];
        }
    }

    ll ret = 0;
    if (N > M) {
        REP(h, N) {
            ll index = 0;
            ll z = 0, o = 0;
            bool e = false;
            while (true) {
                ll nx = h - index;
                ll ny = index;
                if (nx < 0 || ny >= M)
                    break;
                if (S[nx][ny] == 0)
                    z++;
                else
                    o++;
                if (S[N - 1 - nx][M - 1 - ny] == 0)
                    z++;
                else
                    o++;
                S[nx][ny] = S[N - 1 - nx][M - 1 - ny] = 0;
                if (h == N - 1 - nx && M - 1 - ny == 0)
                    e = true;
                index++;
            }
            if (!e)
                ret += std::min(z, o);
        }
    }
    else {
        REP(w, M) {
            ll index = 0;
            ll z = 0, o = 0;
            bool e = false;
            while (true) {
                ll ny = w - index, nx = index;
                if (ny < 0 || nx >= N)
                    break;
                if (S[nx][ny] == 0)
                    z++;
                else
                    o++;
                if (S[N - 1 - nx][M - 1 - ny] == 0)
                    z++;
                else
                    o++;
                S[nx][ny] = S[N - 1 - nx][M - 1 - ny] = 0;
                if (0 == N - 1 - nx && M - 1 - ny == w)
                    e = true;
                index++;
            }
            if (!e)
                ret += std::min(z, o);
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}