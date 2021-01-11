#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 600005;

ll S[MAX];
struct Data {
    ll a, b, c;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;
    memset(S, 0, sizeof(S));
    vector<Data> d(N);
    vector<ll> v;
    REP(i, N) {
        cin >> d[i].a >> d[i].b >> d[i].c;
        v.push_back(d[i].a);
        v.push_back(d[i].b);
        v.push_back(d[i].b + 1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, N) {
        ll a = lower_bound(v.begin(), v.end(), d[i].a) - v.begin();
        ll b = lower_bound(v.begin(), v.end(), d[i].b) - v.begin();
        S[a] += d[i].c;
        S[b + 1] -= d[i].c;
    }

    FOR(i, v.size() + 1, 1) {
        S[i] += S[i - 1];
    }
#if false
    REP(i, v.size()) {
        cout << S[i] << "," << v[i] << endl;
    }
    cout << endl;
#endif
    ll ans = 0;

    FOR(i, v.size(), 1) {
        ll x = v[i] - v[i - 1];
        ll c = std::min(S[i - 1], C);
        ans += c * x;
    }
    // ans += std::min(C, S[v.size() - 2]);
    cout << ans << endl;

    return 0;
}