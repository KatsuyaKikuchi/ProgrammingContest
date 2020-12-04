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
    ll N, K, W;
    IN >> N >> K >> W;
    vector<ll> L(N);
    REP(i, K) {
        IN >> L[i];
    }
    ll AL, BL, CL, DL;
    IN >> AL >> BL >> CL >> DL;
    FOR(i, N, K) {
        L[i] = (AL * L[i - 2] + BL * L[i - 1] + CL) % DL + 1;
    }
    vector<ll> H(N);
    REP(i, K) {
        IN >> H[i];
    }
    ll AH, BH, CH, DH;
    IN >> AH >> BH >> CH >> DH;
    FOR(i, N, K) {
        H[i] = (AH * H[i - 2] + BH * H[i - 1] + CH) % DH + 1;
    }

    vector<ll> P(N);
    P[0] = (H[0] + W) * 2LL;
    FOR(i, N, 1) {
        P[i] = P[i - 1];
        if (L[i - 1] + W < L[i]) {
            P[i] += (H[i] + W) * 2LL;
            P[i] %= MOD;
            continue;
        }

        ll w = L[i] - L[i - 1];
        P[i] += 2LL * w;
        ll h = 0;
        REP(_, W + 1) {
            ll j = i - 1 - _;
            if (j < 0 || L[j] + W < L[i])
                break;
            h = std::max(h, H[j]);
        }
        P[i] += 2LL * std::max(0LL, H[i] - h);
        P[i] %= MOD;
    }

    ll ret = 1;
    REP(i, N) {
        ret = (ret * P[i]) % MOD;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 1/A.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 1/A_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs, ws) << endl;
    }
    return 0;
}