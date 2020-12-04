#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    pll s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    vector<string> S(H);
    vector<vector<vector<ll>>> C(H);
    REP(i, H) {
        cin >> S[i];
    }

    REP(i, H) {
        vector<vector<ll>> v(W);
        REP(j, W) {
            v[j] = vector<ll>();
            REP(k, 4) {
                v[j].push_back(INF);
            }
        }
        C[i] = v;
    }

    queue<tuple<pll, ll>> q;
    q.push(make_tuple(s, 0));
    REP(i, 4) {
        C[s.first][s.second][i] = 0;
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        pll p = get<0>(t);
        ll cost = get<1>(t) + 1;
        REP(i, 4) {
            REP(d, K) {
                ll nx = x[i] * (d + 1) + p.first, ny = y[i] * (d + 1) + p.second;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    break;
                if (S[nx][ny] == '@')
                    break;
                if (C[nx][ny][i] <= cost)
                    break;
                bool e = false;
                REP(k, 4) {
                    if (C[nx][ny][k] < cost)
                        e = true;
                }
                if (e)
                    break;
                C[nx][ny][i] = cost;
                q.push(make_tuple(pll(nx, ny), cost));
            }
        }
    }

    ll ans = INF;
    REP(i, 4) {
        ans = std::min(C[g.first][g.second][i], ans);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}