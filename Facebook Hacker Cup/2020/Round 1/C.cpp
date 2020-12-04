#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> data;

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

ll solve(std::ifstream &rs, std::ofstream &ws) {
    ll N, K;
    IN >> N >> K;
    vector<ll> L(N), W(N), H(N);
    REP(i, K) {
        IN >> L[i];
    }
    {
        ll a, b, c, d;
        IN >> a >> b >> c >> d;
        FOR(i, N, K) {
            L[i] = (L[i - 2] * a + L[i - 1] * b + c) % d + 1;
        }
    }
    REP(i, K) {
        IN >> W[i];
    }
    {
        ll a, b, c, d;
        IN >> a >> b >> c >> d;
        FOR(i, N, K) {
            W[i] = (W[i - 2] * a + W[i - 1] * b + c) % d + 1;
        }
    }
    REP(i, K) {
        IN >> H[i];
    }
    {
        ll a, b, c, d;
        IN >> a >> b >> c >> d;
        FOR(i, N, K) {
            H[i] = (H[i - 2] * a + H[i - 1] * b + c) % d + 1;
        }
    }

    vector<ll> P(N + 1, 0);
    std::set<data> s;
    s.insert(data(pll(-INF, -INF), 0));
    s.insert(data(pll(INF, INF), 0));

    REP(i, N) {
        data p(pll(L[i], L[i] + W[i]), H[i]);
        ll w = W[i];
        ll sum = 0;

        auto it = s.lower_bound(p);
        it--;
        while (true) {
            if (it->first.first > p.first.second)
                break;

            if (it->first.second < p.first.first) {
                it++;
                continue;
            }

            ll len = std::min(it->first.second, p.first.second) - std::max(it->first.first, p.first.first);
            w -= len;
            sum += (it->first.second - it->first.first + it->second) * 2LL;

            p.first.first = std::min(p.first.first, it->first.first);
            p.first.second = std::max(p.first.second, it->first.second);

            it = s.erase(it);
        }

        P[i] += 2LL * (p.first.second - p.first.first + p.second) - sum;

        s.insert(p);
        P[i + 1] = P[i];
    }

    REP(i, N) {
        cout << P[i] << " ";
    }
    cout << endl;
    ll ret = 1;
    REP(i, N) {
        ret = (ret * P[i] % MOD) % MOD;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 1/C.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 1/C_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs, ws) << endl;
    }
    return 0;
}