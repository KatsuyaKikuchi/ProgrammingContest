#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[505];
long double P[505 * 505];
ll N, M;
bool U[505][505];
pll s, g;
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

bool check(long double mx) {
    memset(U, 0, sizeof(U));
    queue<tuple<pll, ll>> q;
    q.push(make_tuple(s, 0));
    U[s.first][s.second] = true;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        pll p = get<0>(t);
        ll cost = get<1>(t) + 1;
        REP(i, 4) {
            ll nx = p.first + x[i], ny = p.second + y[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (U[nx][ny])
                continue;
            if (S[nx][ny] == '#')
                continue;
            ll num = S[nx][ny] - '0';
            if (num > 0 && (long double) (num) * P[cost] < mx)
                continue;
            U[nx][ny] = true;
            q.push(make_tuple(pll(nx, ny), cost));
        }
    }

    return U[g.first][g.second];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) {
        cin >> S[i];
    }
    REP(i, N) {
        REP(j, M) {
            if (S[i][j] == 's') {
                s = pll(i, j);
                S[i][j] = '0';
            }
            if (S[i][j] == 'g') {
                g = pll(i, j);
                S[i][j] = '0';
            }
        }
    }

    P[0] = 1;
    REP(i, N * M + 5) {
        P[i + 1] = P[i] * 0.99;
    }

    long double ok = -1, ng = 10;
    REP(_, 50) {
        long double mid = (ok + ng) * 0.5;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << OF64 << ok << endl;
    return 0;
}