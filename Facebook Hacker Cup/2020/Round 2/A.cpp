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
const ll INF = (ll) 1e18;

bool check(ll x, const vector<ll> &S, const vector<ll> &X, const vector<ll> &Y) {
    ll N = S.size();
    ll low = 0, hight = 0;
    REP(i, N) {
        if (S[i] < X[i])
            low += X[i] - S[i];
        if (S[i] > X[i] + Y[i])
            hight += S[i] - (X[i] + Y[i]);
    }
    return std::max(low, hight) <= x;
}

ll solve(std::ifstream &rs, std::ofstream &ws) {
    ll N, K;
    IN >> N >> K;
    vector<ll> S(N), X(N), Y(N);
    REP(i, K) {
        IN >> S[i];
    }
    {
        ll A, B, C, D;
        IN >> A >> B >> C >> D;
        FOR(i, N, K) {
            S[i] = (A * S[i - 2] + B * S[i - 1] + C) % D;
        }
    }
    REP(i, K) {
        IN >> X[i];
    }
    {
        ll A, B, C, D;
        IN >> A >> B >> C >> D;
        FOR(i, N, K) {
            X[i] = (A * X[i - 2] + B * X[i - 1] + C) % D;
        }
    }
    REP(i, K) {
        IN >> Y[i];
    }
    {
        ll A, B, C, D;
        IN >> A >> B >> C >> D;
        FOR(i, N, K) {
            Y[i] = (A * Y[i - 2] + B * Y[i - 1] + C) % D;
        }
    }

    ll s = 0, mn = 0, mx = 0;
    REP(i, N) {
        s += S[i];
        mn += X[i];
        mx += (X[i] + Y[i]);
    }
    if (s < mn || mx < s) {
        return -1;
    }

    ll ret = INF, ng = -1;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        if (check(mid, S, X, Y))
            ret = mid;
        else
            ng = mid;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 2/A.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 2/A_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs, ws) << endl;
    }
    return 0;
}