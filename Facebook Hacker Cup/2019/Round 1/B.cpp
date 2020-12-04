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

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll solve(std::ifstream &rs) {
    ll N, K;
    IN >> N >> K;
    string S;
    IN >> S;

    ll ret = 0;
    ll a = 0, b = 0;
    ll index = N - 1;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == 'A')
            a++;
        else
            b++;

        if (b > a + K) {
            ret += modpow(2LL, i + 1);
            ret %= MOD;
            a++;
            b--;
            S[i] = 'A';
        }

        while (a > b) {
            char c = S[index--];
            if (c == 'A')
                a--;
            else
                b--;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2019/Round 1/B.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2019/Round 1/B_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs) << endl;
    }
    return 0;
}