#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[20];
//! < 0 ^1 >2 _3
bool C[20][20][20][20][4];
ll x[4] = {0, -1, 0, 1};
ll y[4] = {-1, 0, 1, 0};

struct Data {
    pll g;
    ll dir;
    pll m;
};

int main() {
    ll A, B, H, W;
    cin >> A >> B >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    memset(C, 0, sizeof(C));
    queue<Data> q;
    q.push(Data{pll(1, 1), 3, pll(A, B)});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        C[t.g.first][t.g.second][t.m.first][t.m.second][t.dir] = true;

        pll g = t.g;
        ll d = t.dir;
        REP(i, 4) {
            if (abs(i - d) == 2)
                continue;
            ll a = t.m.first;
            ll b = t.m.second;
            if ((d - i + 4) % 4 == 1)
                a--;
            if ((i - d + 4) % 4 == 1)
                b--;

            if (a < 0 || b < 0)
                continue;

            pll n = pll(g.first + x[i], g.second + y[i]);
            if (S[n.first][n.second] == '#')
                continue;
            if (C[n.first][n.second][a][b][i])
                continue;
            C[n.first][n.second][a][b][i] = true;
            q.push(Data{n, i, pll(a, b)});
        }
    }

    bool exist = false;
    REP(i, 4) {
        if (C[H - 2][W - 2][0][0][i])
            exist = true;
    }

    if (exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}