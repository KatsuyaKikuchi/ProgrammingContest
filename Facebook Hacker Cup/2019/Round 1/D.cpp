#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define DEBUG 1
#ifdef DEBUG
#define OUT cout
#define IN cin
#else
#define OUT ws
#define IN rs
#endif

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(std::ifstream &rs) {
    ll N, H, V;
    IN >> N >> H >> V;
    vector<pll> G(N);
    {
        ll X0, X1, A, B, C, D;
        IN >> X0 >> X1 >> A >> B >> C >> D;
        G[0].first = X0;
        G[1].first = X1;
        FOR(i, N, 2) {
            G[i].first = (G[i - 2].first * A + G[i - 1].first * B + C) % D + 1;
        }
    }
    {
        ll Y0, Y1, A, B, C, D;
        IN >> Y0 >> Y1 >> A >> B >> C >> D;
        G[0].second = Y0;
        G[1].second = Y1;
        FOR(i, N, 2) {
            G[i].second = (G[i - 2].second * A + G[i - 1].second * B + C) % D + 1;
        }
    }
    if (H + V < N)
        return -1;
    ll ret = INF;
    sort(G.begin(), G.end(), [](pll a, pll b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });
    G.push_back(pll(0, 0));
    ll mh = G[0].first, mv = 0;
    ll h = N, v = 0;
    if (h <= H)
        ret = mh + mv;
    REP(i, N) {
        h--;
        v++;
        mh = G[i + 1].first;
        mv = std::max(mv, G[i].second);
        if (h <= H && v <= V) {
            ret = std::min(ret, mh + mv);
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2019/Round 1/D.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2019/Round 1/D_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs) << endl;
    }
    return 0;
}