#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(ll N, ll L, ll R) {

    if (L == N * (N - 1) + 1) {
        cout << 1 << endl;
        return;
    }
    vector<ll> v;
    ll n = 1;
    ll p = (N - 1) * 2LL;
    ll s = 0;
    while (s + p < L) {
        s += p;
        p -= 2;
        n++;
    }

    ll m = R - L + 1;
    while (v.size() < m + (L - s - 1)) {
        if (n == N)
            v.push_back(1);

        for (ll i = n + 1; i <= N; ++i) {
            v.push_back(n);
            v.push_back(i);
        }
        n++;
    }

    REP(i, m) {
        cout << v[i + (L - s - 1)] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, L, R;
        cin >> N >> L >> R;
        solve(N, L, R);
    }
    return 0;
}