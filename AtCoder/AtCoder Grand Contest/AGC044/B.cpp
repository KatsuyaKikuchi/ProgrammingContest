#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505][505];
bool U[505][505];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            A[i][j] = std::min({i, j, N - 1 - i, N - 1 - j});
        }
    }
    ll ans = 0;
    REP(_, N * N) {
        ll a;
        cin >> a;
        a--;
        pll p(a / N, a % N);
        ll c = A[p.first][p.second];
        ans += c;
        U[p.first][p.second] = true;

        queue<tuple<ll, ll, ll>> q;
        q.push(make_tuple(p.first, p.second, c));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            ll cost = get<2>(t);
            if (!U[get<0>(t)][get<1>(t)])
                cost++;
            REP(j, 4) {
                ll nx = x[j] + get<0>(t), ny = y[j] + get<1>(t);
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                if (A[nx][ny] <= cost)
                    continue;

                A[nx][ny] = cost;
                q.push(make_tuple(nx, ny, A[nx][ny]));
            }
        }

#if false
        cout << "-------------------" << endl;
        REP(j, N) {
            REP(k, N) {
                if (j == p.first && k == p.second)
                    cout << "x ";
                else
                    cout << A[j][k] << " ";
            }
            cout << endl;
        }
#endif
    }
    cout << ans << endl;
    return 0;
}