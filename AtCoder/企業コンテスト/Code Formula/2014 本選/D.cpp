#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll type;
    pll range;
    ll nxt = -1;
};
ll H[3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].type >> D[i].range.first >> D[i].range.second;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.range.second < b.range.second; });
    vector<ll> v;
    REP(i, N) {
        v.push_back(D[i].range.first);
        v.push_back(D[i].range.second);
        FOR(j, N, i + 1) {
            if (D[i].type != D[j].type)
                continue;
            if (D[i].range.second <= D[j].range.first) {
                D[i].nxt = j;
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll idx = 0;
    vector<ll> dp(v.size() + 1, 0);
    REP(i, v.size()) {
        while (idx < N && D[idx].range.first <= v[i]) {
            ll ti = idx++;
            ll cnt = 0;
            ll sum = 0;
            ll s = lower_bound(v.begin(), v.end(), D[ti].range.first) - v.begin();
            while (ti != -1) {
                sum += H[cnt++];
                ll end = lower_bound(v.begin(), v.end(), D[ti].range.second) - v.begin();
                dp[end] = std::max(dp[end], dp[s] + sum);
                ti = D[ti].nxt;
            }
        }
        dp[i + 1] = std::max(dp[i + 1], dp[i]);
    }

    cout << dp[dp.size() - 1] << endl;
    return 0;
}