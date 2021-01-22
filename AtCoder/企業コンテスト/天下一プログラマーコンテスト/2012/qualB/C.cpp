#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll str2time(string s) {
    ll ret = (s[0] - '0') * 10 + (s[1] - '0');
    ret *= 60;
    ret += (s[3] - '0') * 10 + (s[4] - '0');
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> T(N);
    REP(i, N) {
        string s, t;
        cin >> s >> t;
        T[i].first = str2time(s);
        T[i].second = str2time(t);
    }
    ll bit = pow(2LL, N);
    vector<ll> dp(bit, INF);
    dp[0] = 0;
    REP(b, bit) {
        vector<ll> v;
        REP(i, N) {
            if ((b >> i) & 1)
                v.push_back(i);
        }
        vector<ll> t;
        t.push_back(0);
        t.push_back(INF);
        REP(i, v.size()) {
            t.push_back(T[v[i]].first);
            if (T[v[i]].second >= 24 * 60)
                t.push_back(T[v[i]].second - 24 * 60);
            else
                t.push_back(T[v[i]].second);
        }

        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        vector<ll> time(t.size() + 2, 0);
        REP(i, v.size()) {
            ll idx0 = lower_bound(t.begin(), t.end(), T[v[i]].first) - t.begin();
            time[idx0]++;
            if (T[v[i]].second >= 24 * 60) {
                ll idx1 = lower_bound(t.begin(), t.end(), T[v[i]].second - 24 * 60) - t.begin();
                time[0]++;
                time[idx1]--;
            }
            else {
                ll idx1 = lower_bound(t.begin(), t.end(), T[v[i]].second) - t.begin();
                time[idx1]--;
            }
        }

        bool enable = true;
        REP(i, time.size()) {
            if (time[i] > 1)
                enable = false;
            if (i < time.size() - 1)
                time[i + 1] += time[i];
        }
        if (enable)
            dp[b] = 1;

        for (ll i = b; i > 0; i = ((i - 1) & b)) {
            dp[b] = std::min(dp[b], dp[i] + dp[b - i]);
        }
    }
    cout << dp[bit - 1] << endl;
    return 0;
}