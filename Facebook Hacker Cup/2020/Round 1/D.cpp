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

bool check(const vector<ll> &P, const vector<ll> &Q, ll S, ll mid) {
    ll N = P.size(), M = Q.size();
    ll index = 0;
    REP(i, N) {
        ll l_len = std::max(0LL, P[i] - Q[index]);
        if (l_len > mid)
            return false;
        ll s = l_len;
        while (index < M) {
            if (Q[index] > P[i])
                break;
            if (s + S > mid)
                break;
            index++;
            s += S;
        }

        if (index >= M)
            break;
        if (Q[index] > P[i]) {
            while (index < M) {
                ll r_len = Q[index] - P[i];
                if (s + S + r_len + std::min(r_len, l_len) > mid)
                    break;
                index++;
                s += S;
            }
        }
        if (index >= M)
            break;
    }

    return index >= M;
}

ll solve(std::ifstream &rs, std::ofstream &ws) {
    ll N, M, K, S;
    IN >> N >> M >> K >> S;
    vector<ll> P(N), Q(M);
    REP(i, K) {
        IN >> P[i];
    }
    {
        ll a, b, c, d;
        IN >> a >> b >> c >> d;
        FOR(i, N, K) {
            P[i] = (P[i - 2] * a + P[i - 1] * b + c) % d + 1;
        }
    }
    REP(i, K) {
        IN >> Q[i];
    }
    {
        ll a, b, c, d;
        IN >> a >> b >> c >> d;
        FOR(i, M, K) {
            Q[i] = (Q[i - 2] * a + Q[i - 1] * b + c) % d + 1;
        }
    }

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    ll ret = INF, ng = 0;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        if (check(P, Q, S, mid))
            ret = mid;
        else
            ng = mid;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 1/D.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 1/D_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs, ws) << endl;
    }
    return 0;
}