#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(std::ifstream& rs) {
    ll N;
    rs >> N;
    vector<pll> A(N);
    REP(i, N) {
        rs >> A[i].first >> A[i].second;
    }

    map<ll, ll> M;
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    ll ret = 0;
    REP(i, N) {
        ll x = A[i].first;
        ll h = A[i].second;
        {
            //! right
            ll d = h + M[x];
            ret = std::max(ret, d);
            M[x + h] = std::max(M[x + h], d);
        }
        {
            //! left
            ll d = h + M[x - h];
            ret = std::max(ret, h + M[x - h]);
            M[x] = std::max(M[x], d);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

#if true
    std::string rFile = "../Facebook Hacker Cup/2020/Qualification Round/C.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Qualification Round/C_ans.txt";
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