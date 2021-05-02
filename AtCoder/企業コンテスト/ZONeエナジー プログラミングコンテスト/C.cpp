#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll P[5];
};
vector<Data> D;

bool check(ll m) {
    ll N = D.size();
    ll bit = pow(2LL, 5);
    vector<ll> v;
    REP(i, N) {
        ll b = 0;
        REP(j, 5) {
            if (D[i].P[j] >= m)
                b |= (1LL << j);
        }
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, v.size()) {
        REP(j, v.size()) {
            REP(k, v.size()) {
                ll b = (v[i] | v[j] | v[k]);
                if (b + 1 == bit)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    D.resize(N);
    REP(i, N) {
        REP(j, 5) {
            cin >> D[i].P[j];
        }
    }

    ll ans = 0, ng = INF;
    while (abs(ng - ans) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;

    return 0;
}