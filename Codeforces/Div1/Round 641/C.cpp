#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18 + 5;

ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};
ll N, M, T;
vector<string> S;
ll C[1005][1005];

int solve() {
    ll h, w, p;
    cin >> h >> w >> p;
    h--;
    w--;
    ll t = C[h][w];
    if (p <= t)
        return S[h][w] - '0';

    ll m = (p - t) % 2;
    ll ret = (S[h][w] - '0' + m) % 2;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> T;
    REP(i, N) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    queue<tuple<int, int, int>> q;
    REP(i, N) {
        REP(j, M) {
            C[i][j] = INF;
            REP(n, 4) {
                ll nx = x[n] + i, ny = j + y[n];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (S[nx][ny] == S[i][j]) {
                    C[i][j] = 0;
                    q.push(make_tuple(i, j, 0));
                    break;
                }
            }
        }
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ll cost = get<2>(t) + 1;
        REP(i, 4) {
            ll nx = x[i] + get<0>(t), ny = y[i] + get<1>(t);
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (C[nx][ny] <= cost)
                continue;
            C[nx][ny] = cost;
            q.push(make_tuple(nx, ny, cost));
        }
    }

    REP(i, T) {
        cout << solve() << endl;
    }

    return 0;
}