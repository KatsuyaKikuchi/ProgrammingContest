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
    ll N, D, M;
    cin >> N >> D >> M;

    priority_queue<ll, vector<ll> > q0;
    vector<ll> v;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a > M)
            q0.push(a);
        else
            v.push_back(a);
    }

    sort(v.begin(), v.end());
    deque<ll> q1;
    REP(i, v.size()) {
        q1.push_back(v[i]);
    }

    ll ans = 0;
    ll n = q0.size();
    ll x = std::max(0LL, n - 1) % (D + 1);
    REP(_, (n + D) / (D + 1)) {
        ll t = q0.top();
        q0.pop();
        ans += t;
    }

    while (!q0.empty() && q1.size() > D) {
        ll t = q0.top();
        q0.pop();
        ll s = 0;
        ll d = D;
        if (x-- <= 0)
            d++;
        REP(_, d) {
            s += q1.front();
            q1.pop_front();
        }
        ans += std::max(s, t);
        if (s >= t)
            break;
        if (d == D) {
            ans += q1.back();
            q1.pop_back();
        }
    }
    while (!q1.empty()) {
        ll t = q1.front();
        q1.pop_front();
        ans += t;
    }
    cout << ans << endl;
    return 0;
}