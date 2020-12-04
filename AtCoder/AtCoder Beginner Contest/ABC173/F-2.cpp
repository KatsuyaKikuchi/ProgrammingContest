#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

Vertex V[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    vector<ll> S(N + 1, 0);
    for (ll i = N - 1; i >= 0; --i) {
        ll v = 1;
        REP(j, V[i].node.size()) {
            if (V[i].node[j] > i)
                v--;
        }
        S[i] = S[i + 1] + v;
    }

    ll ans = 0;
    ll sum = 0;
    REP(i, N) {
        sum += S[i];
    }
    for (ll i = N - 1; i >= 0; --i) {
        ans += sum;
        vector<ll> v;
        REP(j, V[i].node.size()) {
            ll idx = V[i].node[j];
            if (idx < i)
                v.push_back(idx);
        }
        sort(v.begin(), v.end());
        REP(j, static_cast<ll>(v.size()) - 1) {
            sum += v[j] + 1;
        }
        ll mx = -1;
        if (v.size() > 0)
            mx = v[v.size() - 1];
        sum -= i - mx;
    }

    cout << ans << endl;
    return 0;
}