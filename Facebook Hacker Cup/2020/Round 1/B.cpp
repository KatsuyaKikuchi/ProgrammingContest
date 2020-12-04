#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

//#define DEBUG 1
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
    std::set<pll> s;
    s.insert(pll(-INF, -INF));
    s.insert(pll(INF, INF));

    REP(i, N) {
        pll p(L[i], L[i] + W[i]);
        ll w = W[i];
        ll num = 0;

        auto it = s.lower_bound(p);
        it--;
        while (true) {
            if (it->first > p.second)
                break;

            if (it->second < p.first) {
                it++;
                continue;
            }

            ll len = std::min(it->second, p.second) - std::max(it->first, p.first);
            w -= len;

            p.first = std::min(p.first, it->first);
            p.second = std::max(p.second, it->second);
            num += 2LL;

            it = s.erase(it);
        }

        P[i] += 2LL * std::max(w, 0LL);
        // if (p.first == L[i] && p.second == L[i] + W[i])
        //    P[i] += 2LL * H[i];
        P[i] += (2LL - num) * H[i];

        s.insert(p);
        P[i] %= MOD;
        P[i + 1] = P[i];
    }

#if false
    REP(i, N) {
        cout << P[i] << " ";
    }
    cout << endl;
#endif

    ll ret = 1;
    REP(i, N) {
        ret = (ret * P[i]) % MOD;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 1/B.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 1/B_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs, ws) << endl;
    }
    return 0;
}