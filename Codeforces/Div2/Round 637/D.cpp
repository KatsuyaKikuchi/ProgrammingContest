#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[2005];
ll P[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
            0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
ll T[150][10];

bool dp[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        string s;
        cin >> s;
        ll n = 0;
        REP(j, s.length()) {
            if (s[s.length() - j - 1] == '1')
                n |= (1 << j);
        }
        S[i] = n;
    }

    memset(T, -1, sizeof(T));
    REP(i, pow(2, 7)) {
        REP(j, 10) {
            if ((i & P[j]) != i)
                continue;

            ll m = (~i) & P[j];
            ll s = 0;
            while (m > 0) {
                if (m & 1)
                    s++;
                m >>= 1;
            }
            T[i][s] = std::max(j, T[i][s]);
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[N][K] = true;
    for (ll i = N - 1; i >= 0; --i) {
        REP(j, K + 1) {
            if (!dp[i + 1][j])
                continue;

            REP(n, 8) {
                ll t = T[S[i]][n];
                if (t < 0)
                    continue;
                if (j - n < 0)
                    continue;
                dp[i][j - n] = true;
            }
        }
    }

    string ret = "";
    ll sum = 0;
    REP(i, N) {
        vector<pll> v;
        REP(j, 8) {
            ll t = T[S[i]][j];
            if (t < 0)
                continue;
            v.push_back(pll(t, j));
        }
        sort(v.begin(), v.end(), [](pll a, pll b) { return a.first > b.first; });
        bool exist = false;
        REP(j, v.size()) {
            ll n = v[j].second;
            if (!dp[i + 1][sum + n])
                continue;

            exist = true;
            ret.push_back((char) (v[j].first + '0'));
            sum += n;
            break;
        }
        if (!exist)
            break;
    }

    if (ret.size() == N)
        cout << ret << endl;
    else
        cout << -1 << endl;

    return 0;
}