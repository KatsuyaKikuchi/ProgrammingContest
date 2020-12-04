#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];

ll modpow(ll n, ll p, ll mod) {
    ll ret = 1;
    ll m = n;
    while (p > 0) {
        if (p & 1)
            ret = (ret * m) % mod;
        m = (m * m) % mod;
        p >>= 1LL;
    }
    return ret;
}

const long long mod[] = {999999937LL, 1000000007LL, 100000007LL}, base = 9973;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));

    map<pll, ll> map;

    REP(i, N + 1) {
        if (i >= K) {

            pll hash(0, 0);
            REP(c, 27) {
                hash.first += modpow(base, c, mod[0]) * C[c] % mod[0];
                hash.second += modpow(base, c, mod[1]) * C[c] % mod[1];
            }

            ll index = map[hash];
            //cout << index << endl;

            if (index > 0 && i - K >= index) {
                cout << "YES" << endl;
                return 0;
            }
            if (index == 0)
                map[hash] = i;
            if (i >= N)
                break;
            C[S[i - K] - 'a']--;
        }
        C[S[i] - 'a']++;
    }

    cout << "NO" << endl;

    return 0;
}