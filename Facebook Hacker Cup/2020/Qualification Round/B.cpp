#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(std::ifstream& rs) {
    ll N;
    string S;
    rs >> N >> S;
    ll a = 0, b = 0;
    REP(i, N) {
        if (S[i] == 'A')
            a++;
        else
            b++;
    }

    if (abs(a - b) == 1)
        return "Y";
    return "N";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

#if true
    std::string rFile = "../Facebook Hacker Cup/2020/Qualification Round/B.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Qualification Round/B_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);
#endif
    ll Q;
    rs >> Q;
    REP(i, Q) {
        ws << "Case #" << i + 1 << ": ";
        ws << solve(rs) << endl;
    }
    return 0;
}