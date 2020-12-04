#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];
ll P[100005];
vector<ll> S[200005];
vector<ll> R[200005];

int main() {
    ll N, W, C;
    cin >> N >> W >> C;
    vector<ll> v;
    REP(i, N) {
        cin >> A[i].first >> A[i].second >> P[i];
        v.push_back(A[i].first);
        v.push_back(A[i].second);
    }
    v.push_back(0);
    v.push_back(W);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, N) {
        ll r = lower_bound(v.begin(), v.end(), A[i].second) - v.begin();
        ll l = lower_bound(v.begin(), v.end(), A[i].first) - v.begin();
        S[l].push_back(P[i]);
        R[r].push_back(P[i]);
    }

    ll ans = INF;
    ll sum = 0;
    ll li = 0;
    REP(i, v.size()) {
        ll r = v[i];
        while (r - v[li] >= C) {
            ans = std::min(ans, sum);
            li++;
            REP(j, R[li].size()) {
                sum -= R[li][j];
            }
        }
        REP(j, S[i].size()) {
            sum += S[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}