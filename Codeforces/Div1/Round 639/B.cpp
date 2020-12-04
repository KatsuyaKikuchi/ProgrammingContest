#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[1005];
bool U[1005][1005];
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};

bool H[1005], W[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> S[i];
    }

    memset(H, 0, sizeof(H));
    memset(W, 0, sizeof(W));
    bool exist = true;
    REP(i, N) {
        ll d = -1;
        ll num = 0;
        REP(j, M) {
            if (S[i][j] == '.') {
                num++;
                continue;
            }
            if (d >= 0 && j - d > 1)
                exist = false;
            d = j;
        }
        if (num == M)
            H[i] = true;
    }
    REP(j, M) {
        ll d = -1;
        ll num = 0;
        REP(i, N) {
            if (S[i][j] == '.') {
                num++;
                continue;
            }
            if (d >= 0 && i - d > 1)
                exist = false;
            d = i;
        }
        if (num == N)
            W[j] = true;
    }

    REP(i, N) {
        if (!H[i])
            continue;
        bool e = false;
        REP(j, M) {
            if (W[j]) {
                e = true;
                break;
            }
        }
        exist &= e;
    }
    REP(i, M) {
        if (!W[i])
            continue;
        bool e = false;
        REP(j, N) {
            if (H[j]) {
                e = true;
                break;
            }
        }
        exist &= e;
    }

    if (!exist) {
        cout << -1 << endl;
        return 0;
    }
    memset(U, 0, sizeof(U));

    ll ans = 0;
    REP(i, N) {
        REP(j, M) {
            if (U[i][j])
                continue;
            if (S[i][j] == '.')
                continue;
            ans++;
            queue<pll> q;
            q.push(pll(i, j));
            U[i][j] = true;
            while (!q.empty()) {
                pll t = q.front();
                q.pop();
                REP(n, 4) {
                    ll nx = t.first + x[n], ny = t.second + y[n];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if (U[nx][ny] || S[nx][ny] == '.')
                        continue;
                    U[nx][ny] = true;
                    q.push(pll(nx, ny));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}