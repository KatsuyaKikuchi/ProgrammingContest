#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dpL[200005];
ll dpR[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    memset(dpL, 0, sizeof(dpL));
    memset(dpR, 0, sizeof(dpR));
    {
        ll max = 0;
        REP(i, N) {
            dpL[i] = max;
            if (S[i] == 'o') {
                ll m = 1;
                if (i - (C + 1) >= 0)
                    m += dpL[i - (C + 1)];
                dpL[i] = std::max(dpL[i], m);
            }
            max = std::max(max, dpL[i]);
        }
    }
    vector<ll> v;
    {
        ll max = 0;
        for (ll i = N - 1; i >= 0; --i) {
            ll left = i > 0 ? dpL[i - 1] : 0;
            ll right = dpR[i + 1];
            if (left + right < K)
                v.push_back(i + 1);

            dpR[i] = max;
            if (S[i] == 'o') {
                ll m = 1;
                if (i + C + 1 <= N)
                    m += dpR[i + C + 1];
                dpR[i] = std::max(dpR[i], m);
            }
            max = std::max(dpR[i], max);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}