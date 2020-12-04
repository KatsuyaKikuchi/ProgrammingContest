#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll nxt[4];
};

char C[4] = {'U', 'L', 'D', 'R'};
ll x[4] = {0, -1, 0, 1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    std::map<pll, Data> M;
    pll g(0, 0);
    {
        Data d;
        d.nxt[0] = pll(0, 1);
        d.nxt[1] = pll(-1, 0);
        d.nxt[2] = pll(0, -1);
        d.nxt[3] = pll(1, 0);
        M[g] = d;
    }
    REP(i, N) {
        char c = S[i];
        REP(j, 4) {
            if (C[j] != c)
                continue;
            g = M[g].nxt[j];
            break;
        }
        //cout << g.first << " " << g.second << endl;

        Data d;
        REP(j, 4) {
            pll nxt(g.first + x[j], g.second + y[j]);
            auto it = M.find(nxt);
            if (it == M.end()) {
                d.nxt[j] = nxt;
                continue;
            }
            d.nxt[j] = M[nxt].nxt[j];
        }
        REP(j, 4) {
            pll nxt(d.nxt[j].first - x[j], d.nxt[j].second - y[j]);
            auto it = M.find(nxt);
            if (it == M.end())
                continue;
            M[nxt].nxt[(j + 2) % 4] = d.nxt[(j + 2) % 4];
        }

        M[g] = d;
    }
    cout << g.first << " " << g.second << endl;
    return 0;
}