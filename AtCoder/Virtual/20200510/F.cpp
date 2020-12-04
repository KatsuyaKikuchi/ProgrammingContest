#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N >> S;
    map<pair<string, string>, ll> map;
    REP(p, pow(2LL, N)) {
        string r = "", b = "";
        REP(i, N) {
            if ((p >> i) & 1)
                r.push_back(S[N + i]);
            else
                b.push_back(S[N + i]);
        }
        reverse(b.begin(), b.end());
        map[pair<string, string>(r, b)]++;
    }

    ll ans = 0;
    REP(p, pow(2LL, N)) {
        string r = "", b = "";
        REP(i, N) {
            if ((p >> i) & 1)
                r.push_back(S[i]);
            else
                b.push_back(S[i]);
        }
        reverse(b.begin(), b.end());
        ans += map[pair<string, string>(b, r)];
    }
    cout << ans << endl;
    return 0;
}